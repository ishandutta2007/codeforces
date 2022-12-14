#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,k;
    cin>>n>>k;
    long long need = n-k;
    a[0]=n;
    for (int i=0;i<100;i++)
    {
        if (need<0)break;
        long long can = a[i]/2;
        long long take = min(can,need);
        need-=take;
        a[i]-=take*2;
        a[i+1]+=take;
        if (need==0)break;
    }
    if (need!=0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for (int i=0;i<100;i++)
        {
            for (int j=0;j<a[i];j++)
                cout<<(1LL<<i)<<' ';
        }
        cout<<endl;
    }
}