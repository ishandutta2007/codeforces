#include <bits/stdc++.h>
using namespace std;
#define ll long long
multiset<char> s1;
multiset<char> s2;
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    for (int i=0;i<b.size();i++)
        s1.insert(b[i]),s2.insert(b[i]);
    int L=0,R=0;
    for (int i=0;i<n;i++)
    {
        char x = a[i];
        if (s1.lower_bound(x)==s1.end())
            L++;
        else
            s1.erase(s1.lower_bound(x));
        if (s2.upper_bound(x)==s2.end())
            ;
        else
            R++,s2.erase(s2.upper_bound(x));
    }
    cout<<L<<endl<<R<<endl;
}