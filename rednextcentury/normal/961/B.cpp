#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int t[1000000];
int pre[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    int ret=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>t[i];
        if (t[i]==1){
            ret += a[i];
            a[i]=0;
        }
        pre[i] = pre[i-1]+a[i];
    }
    int mx=0;
    for (int i=1;i+k-1<=n;i++)
        mx=max(mx,pre[i+k-1]-pre[i-1]);
    cout<<mx+ret<<endl;
}