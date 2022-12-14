#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
ll mod=1000000007;
int P[20000000];
bool pr[20000000];
void sieve()
{
    P[1]=1;
    for (int i=2;i<=15000000;i++)
    {
        if (!pr[i])
        {
            P[i]=i;
            for (int j=i+i;j<=15000000;j+=i)
            {
                if (!P[j])P[j]=i;
                pr[j]=1;
            }
        }
    }

}
int ret[15000100];
int main()
{
    fast;
    sieve();
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int last=-1;
        int num=1;
        while(x!=1)
        {
            int cur = P[x];
            if (cur!=last)
                last=cur,num=1;
            num*=cur;
            ret[num]++;
            x/=cur;
        }
    }
    int ans=0;
    for (int i=1;i<=15000000;i++)
    {
        if (ret[i]<n)
            ans=max(ans,ret[i]);
    }
    if(ans==0)ans=n+1;
    cout<<n-ans<<endl;
}