#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

void up()
{
    string s;
    cin>>s;
    vector<int> poss;
    for (int j=2; j<s.size(); j++)
        if (j>=4&&s[j-4]=='t'&&s[j-3]=='w'&&s[j-2]=='o'&&s[j-1]=='n'&&s[j]=='e')
    {
        poss.pop_back();
        poss.pb(j-2);
    } else
        if (s[j-2]=='o'&&s[j-1]=='n'&&s[j]=='e') poss.pb(j-1); else
        if (s[j-2]=='t'&&s[j-1]=='w'&&s[j]=='o') poss.pb(j-1);
    cout<<poss.size()<<"\n";
    for (int j=0; j<poss.size(); j++)
        cout<<poss[j]+1<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}