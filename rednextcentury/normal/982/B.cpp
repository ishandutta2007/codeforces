#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> > s1;
set<pair<int,int> > s2;
#define mp make_pair
int w[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>w[i];
        s2.insert(mp(w[i],i+1));
    }
    string s;
    cin>>s;
    for (int i=0;i<2*n;i++)
    {
        char x=s[i];
        if (x=='0')
        {
            pair<int,int> p = *s2.begin();
            cout<<p.second<<' ';
            s2.erase(s2.begin());
            s1.insert(p);
        }
        else
        {
            pair<int,int> p = *s1.rbegin();
            cout<<p.second<<' ';
            s1.erase(--s1.end());
        }
    }
}