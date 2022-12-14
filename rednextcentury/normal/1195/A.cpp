#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int num=n/2+n%2;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int ret=0;
    for (int i=1;i<=k;i++)
    {
        while(num && a[i]>1)
            a[i]-=2,num--,ret+=2;
    }
    for (int i=1;i<=k;i++)
    {
        while(num && a[i])
            a[i]--,num--,ret+=1;
    }
    cout<<ret<<endl;
}