#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
int p[1000000];
vector<int> v;
void sieve(int n)
{
    for (int i=2;i<=n;i++)
    {
        if (p[i])continue;
        v.push_back(i);
        for (int j=i+i;j<=n;j+=i)
            p[j]=1;
    }
}
vector<pair<int,int> > ret;
int main ()
{
    ll n,m;
    cin>>n>>m;
    if (m+1<n)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for (int i=2;i<=n;i++)
    {
        ret.PB({1,i});
    }
    if (n<=2000)
    {
        for (int i=2;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if (ret.size()<m && __gcd(i,j)==1)
                {
                    ret.PB({i,j});
                }
            }
        }
        if (ret.size()<m)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        else
        {
            cout<<"Possible"<<endl;
            for (int x=0;x<m;x++)
                cout<<ret[x].F<<' '<<ret[x].S<<endl;
            return 0;
        }
    }
    else
    {
        sieve(n);
        for (int i=0;i<v.size();i++)
        {
            for (int j=i+1;j<v.size();j++)
            {
                if (ret.size()<m)
                {
                    ret.PB({v[i],v[j]});
                }
                else
                {
                    cout<<"Possible"<<endl;
                    for (int x=0;x<m;x++)
                        cout<<ret[x].F<<' '<<ret[x].S<<endl;
                    return 0;
                }
            }
        }
        if (ret.size()<m)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        else
        {
            cout<<"Possible"<<endl;
            for (int x=0;x<m;x++)
                cout<<ret[x].F<<' '<<ret[x].S<<endl;
            return 0;
        }
    }
}