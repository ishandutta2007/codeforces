#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 500000
int a[Maxn+5];
ll sum[Maxn+5];
inline void read(int &a){
    a=0;
    register char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a=(a<<1)+(a<<3)+(c^48);
        c=getchar();
    }
}
bool cmp(int p,int q){
    return p>q;
}
template<typename Elem>
Elem mx(Elem a,Elem b){
    return a>b?a:b;
}
template<typename Elem>
Elem mn(Elem a,Elem b){
    return a<b?a:b;
}
int main(){
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll left=0,right=n;
    ll l_s,r_s;
    for(int i=1,j;i<=n;i++){
        j=lower_bound(a+1+i,a+1+n,i,cmp)-a;
        l_s=sum[i];
        r_s=1ll*(j-i-1)*i+1ll*i*(i-1)+sum[n]-sum[j-1];
        if(l_s>r_s){
            if(l_s-r_s>i){
                puts("-1");
                return 0;
            }
            left=mx(left,l_s-r_s);
        }
        right=mn(right,a[i]+i+r_s-l_s);
    }
    if(left>right){
        puts("-1");
        return 0;
    }
    bool get_ans=0;
    for(int i=left;i<=right;i++){
        if(!((i-sum[n])&1)){
            printf("%d ",i);
            get_ans=1;
        }
    }
    if(get_ans){
        puts("");
    }
    else{
        puts("-1");
    }
    return 0;
}