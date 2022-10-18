#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 100 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k0=0,k1=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='0') k0++; else k1++;
    if (k1>0) cout<<1;
    for (int j=1; j<=k0; j++)
        cout<<0;
}