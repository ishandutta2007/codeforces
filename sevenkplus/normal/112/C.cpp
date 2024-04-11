#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;ll x;int y;
int a[100010];
int main()
{
    cin>>n>>x>>y;
    if(y<n){puts("-1");return 0;}
    for(int i=0;i<n;i++)a[i]=y/n;
    for(int i=0;i<y-y/n*n;i++)a[i]++;
    ll S=0;
    for(int i=0;i<n;i++)S+=(ll)a[i]*a[i];
    if(S>=x)
    {
        for(int i=0;i<n;i++)cout<<a[i]<<endl;
        return 0;
    }
    S=0;
    for(int i=0;i<n-1;i++)a[i]=1;
    a[n-1]=y-(n-1);
    for(int i=0;i<n;i++)S+=(ll)a[i]*a[i];
    if(S>=x)
    {
        for(int i=0;i<n;i++)cout<<a[i]<<endl;
        return 0;
    }
    puts("-1");
    return 0;
}