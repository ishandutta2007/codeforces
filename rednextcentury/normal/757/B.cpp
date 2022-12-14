#include<bits/stdc++.h>
using namespace std;
int prime[1000000];
int nxt[1000000];
int GenPrimes()
{
    int mx=100000;
    nxt[2]=2;
    for (int i=2;i<=mx;i++)
    {
        if (prime[i])continue;
        nxt[i]=i;
        for (int j=i+i;j<=mx;j+=i)
        {
            prime[j]=1;
            nxt[j]=i;
        }
    }
}
int num[1000000];
int ans=0;
void Add(int s)
{
    while(1)
    {
        if (s==1)break;
        int x=nxt[s];
        while(s%x==0)
			s/=x;
        num[x]++;
        if (num[x]>ans)
            ans=num[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    GenPrimes();
    int n;
    cin>>n;
    while(n--)
    {
        int s;
        cin>>s;
        Add(s);
    }
    cout<<max(1,ans)<<endl;
}