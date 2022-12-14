#include <bits/stdc++.h>
using namespace std;
bool prime[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    prime[1]=1;
    prime[2]=0;
    for (int i=2;i<=100000;i++)
    {
        if (prime[i])continue;
        for (int j=i+i;j<=100000;j+=i)
            prime[j]=1;
    }
    int n;
    cin>>n;
    bool ok=0;
    int num=-1,two=-1,three=-1;
    for (int i=n/2+n%2;i<=n;i++)
    {
        int left = n-i;
        int cur=i;
        for (int j=0;j<=left;j++)
        {
            int add=2*j + 3*(left-j);
            if (add>i)break;
            if (!prime[add+cur])
            {
                ok=1;
                num=i;
                two=j;
                three=left-j;
                break;
            }
        }
        if (ok)break;
    }
    vector<pair<int,int> > e;
    for (int i=1;i<=num;i++)
    {
        int nxt = i+1;
        if (nxt>num)nxt=1;
        e.push_back({i,nxt});
    }
    int cur=1;
    int cc=num+1;
    for (int i=1;i<=two;i++)
    {
        e.push_back({cc,cur++});
        e.push_back({cc,cur++});
        cc++;
    }
    for (int i=1;i<=three;i++)
    {
        e.push_back({cc,cur++});
        e.push_back({cc,cur++});
        e.push_back({cc,cur++});
        cc++;
    }
    cout<<e.size()<<endl;
    for (auto x:e)
        cout<<x.first<<' '<<x.second<<endl;
}