#include <bits/stdc++.h>
using namespace std;
bool prime[1000000];
int nxt[1000000];
void seive()
{
    prime[1]=1;
    for (int i=2;i<=1000000;i++)
    {
        if (prime[i])continue;
        nxt[i]=i;
        int j=i*2;
        while(j<=1000000)
        {
            prime[j]=1;
            nxt[j]=i;
            j+=i;
        }
    }
}
vector<int> getPrime(int X)
{
    vector<int> vec;
    while(X!=1)
    {
        int x=nxt[X];
        vec.push_back(x);
        while(X%x==0)X/=x;
    }
    return vec;
}
int attempt(int l,int r)
{
    int ret=1000000000;
    for (int i=l;i<=r;i++)
    {
        vector<int> cur=getPrime(i);
        for (int j=0;j<cur.size();j++)
            if ((i-cur[j]+1)!=1)
                ret=min(ret,i-cur[j]+1);
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    seive();
    int ans=1000000000;
    vector<int> vec = getPrime(n);
    for (int i=0;i<vec.size();i++)
    {
        int l=n-vec[i]+1;
        int r=n;
        ans=min(ans,attempt(l,r));
    }
    cout<<ans<<endl;
}