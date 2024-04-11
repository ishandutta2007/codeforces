#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

const int N = 3e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    set<pair<int,int> > st1,st2;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        st1.insert(mp(a[i],i));
    }
    string s;
    cin>>s;
    for (int j=0; j<s.size(); j++)
    if (s[j]=='0')
    {
        pair<int,int> d=*st1.begin();
        cout<<d.ss<<" ";
        st1.erase(d);
        st2.insert(d);
    } else
    {
        pair<int,int> d=*st2.rbegin();
        cout<<d.ss<<" ";
        st2.erase(d);
    }
}