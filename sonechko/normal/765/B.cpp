#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define outld(l) cout.precision(l); cout<<fixed
const int N = 1e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD
int main()
{
    if (0)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]-'a'+1==k+1) {k++;} else
        if (s[i]-'a'+1>k) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}