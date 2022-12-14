#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
ll pre[1000000];
ll getSum(int l,int r){
    if (l>r)return 0;
    if (l==0)return pre[r];
    return pre[r]-pre[l-1];
}
ll getCost(int l,int r){
    int mid = (l+r)/2;
    ll L =  mid-1-l+1;
    ll R = r-(mid+1)+1;
    return a[mid]*L - getSum(l,mid-1) + (getSum(mid+1,r) - a[mid]*R);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if (x==1)a.push_back(i);
    }
    n = a.size();
    pre[0]=a[0];
    for (int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
    ll ret = 1e18;
    for (int len=2;len<=n;len++) {
        if (n%len)continue;
        ll cur=0;
        for (int st=0;st<n;st+=len){
            cur+=getCost(st,st+len-1);
        }
        ret=min(ret,cur);
    }
    if (ret>=1e17)ret=-1;
    cout<<ret<<endl;
}