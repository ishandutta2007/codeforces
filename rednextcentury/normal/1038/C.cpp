#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
multiset<ll> s1,s2;
int main ()
{
    int n;
    cin>>n;
    ll l=0,r=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1.insert(x);
    }
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s2.insert(x);
    }
    for (int i=0;i<2*n;i++)
    {
        if (i%2==0)
        {
            if (s1.empty())
            {
                s2.erase(--s2.end());
            }
            else if (s2.empty())
            {
                l+=*(--s1.end());
                s1.erase(--s1.end());
            }
            else
            {
                if (*(--s1.end()) >= *(--s2.end()))
                {
                    l+=*(--s1.end());
                    s1.erase(--s1.end());
                }
                else
                {
                    s2.erase(--s2.end());
                }
            }
        }
        else
        {
            if (s2.empty())
            {
                s1.erase(--s1.end());
            }
            else if (s1.empty())
            {
                r+=*(--s2.end());
                s2.erase(--s2.end());
            }
            else
            {
                if (*(--s2.end()) >= *(--s1.end()))
                {
                    r+=*(--s2.end());
                    s2.erase(--s2.end());
                }
                else
                {
                    s1.erase(--s1.end());
                }
            }
        }
    }
    cout<<l-r<<endl;
}