#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    while(n--)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    long long sub=0;
    for (int i=0;i<k;i++)
    {
        if (s.empty())
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<*s.begin()-sub<<endl;

            sub = *s.begin();
            s.erase(s.begin());
        }
    }
}