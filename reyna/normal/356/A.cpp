#include<bits/stdc++.h>
using namespace std;
long long l[1000000], r[1000000], x[1000000], seg[2000000];
void update(long long s, long long e, long long us, long long ue, long long k, long long idx){
    if(s==e && s>=us && e<=ue && s!=k && seg[idx]==-1000000000000LL){
        seg[idx]=k;
        return;
    }
    if(e<us || s>ue || seg[idx]>0)
        return;
    if(s==e)
        return;
    long long mid=(s+e)/2;
    update(s, mid, us, ue, k, idx*2);
    update(mid+1, e, us, ue, k, idx*2+1);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
long long query(long long s, long long e, long long q, long long idx){
    if(q==s && q==e)
        return seg[idx];
    if(q<s || q>e)
        return 0;
    long long mid=(s+e)/2;
    return query(s, mid, q, idx*2)+query(mid+1, e, q, idx*2+1);
}
int main(){
long long n, m;
cin>>n>>m;
for(long long i=0; i<2000000; i++)
    seg[i]=-1000000000000LL;
for(long long i=0; i<m; i++){
    cin>>l[i]>>r[i]>>x[i];
    update(1, n, l[i], r[i], x[i], 1);
}
for(long long i=1; i<=n; i++){
    if(query(1, n, i, 1)>0)
        cout<<query(1, n, i, 1)<<" ";
    else
        cout<<0<<" ";
}
return 0;
}