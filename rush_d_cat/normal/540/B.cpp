#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef __int64 ll;
const int INF=100000000;
int a[1002];
int main()
{
    int n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int res=x-sum;
    for(int i=k+1;i<=n;i++)
    {
        a[i]=1;
        res--;
    }
    sort(a+1,a+1+n);
    if(res<0)
    {
        cout<<-1<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=(n+1)/2;i<=n;i++)
    {
        if(a[i]<y) cnt++;
    }
    if(n-k<cnt)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=cnt;i++)
    {
        res -= (y-a[i]);
    }
    if(res<0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n-k;i++)
    {
        if(i<=cnt) cout<<y;
        else cout<<1;
        if(i!=n) cout<<" ";
        else cout<<endl;
    }
    return 0;
}