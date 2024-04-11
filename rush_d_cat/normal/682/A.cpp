#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
int main()
{
    int m,n;cin>>m>>n;
    int a[5],b[5];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=m;i++) a[i%5]++;
    for(int i=1;i<=n;i++) b[i%5]++;
    ll res = 0;
    for(int i=1;i<=4;i++)
    {
        res += (ll)a[i]*(ll)b[5-i];
    }
    res+=(ll)a[0]*(ll)b[0];
    cout<<res<<endl;
    return 0;
}