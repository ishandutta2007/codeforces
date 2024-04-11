#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;

int dp[N][27];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    char ch='a';
    for (int i=0; i<s.size(); i++)
    if (s[i]<=ch) {s[i]=ch; if (ch=='z') {ch='.'; break;} ch++;}
    if (ch=='.') cout<<s<<endl; else cout<<"-1"<<endl;
}