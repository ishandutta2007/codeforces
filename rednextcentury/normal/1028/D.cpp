#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
set<int> buy;
set<int> sell;
set<int> unknown;
int main ()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    buy.insert(0);
    sell.insert(308983067);
    long long ret=1;
    while(n--)
    {
        string s;
        int x;
        cin>>s>>x;
        if (s=="ADD")
        {
            if (x<=*(--buy.end()))
                buy.insert(x);
            else if (x>=*sell.begin())
                sell.insert(x);
            else
                unknown.insert(x);
        }
        else
        {
            if (unknown.find(x)!=unknown.end())
            {
                ret=ret*2;
                ret%=MOD;
                for (set<int>::iterator it=unknown.begin();it!=unknown.end();it++)
                {
                    if (*it==x)continue;
                    if (*it < x)
                        buy.insert(*it);
                    else
                        sell.insert(*it);
                }
                unknown.clear();
            }
            else if (sell.find(x)!=sell.end())
            {
                if (x==*sell.begin())
                {
                    sell.erase(sell.begin());
                    for (set<int>::iterator it=unknown.begin();it!=unknown.end();it++)
                        buy.insert(*it);
                    unknown.clear();
                }
                else
                {
                    ret=0;
                    break;
                }
            }
            else
            {
                if (x==*(--buy.end()))
                {
                    buy.erase(--buy.end());

                    for (set<int>::iterator it=unknown.begin();it!=unknown.end();it++)
                        sell.insert(*it);
                    unknown.clear();
                }
                else
                {
                    ret=0;
                    break;
                }
            }
        }
    }
    long long X = unknown.size()+1;
    cout<<(ret*X)%MOD<<endl;
}