#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back



const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    vector<char> v;
    for (int i=0; i<s.size(); i++)
        if (v.size()==0||v[v.size()-1]!=s[i]) v.pb(s[i]); else
            v.pop_back();
    for (int i=0; i<v.size(); i++)
        cout<<v[i];
}