#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int k1=0,k2=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='A') k1++; else
        if (s[i]=='I') k2++;
    if (k2==0) cout<<k1; else
    if (k2==1) cout<<1; else
    cout<<0;
}