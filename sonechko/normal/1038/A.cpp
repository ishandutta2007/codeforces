#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<=n; i++)
        kol[s[i]-'A']++;
    int t=100000000;
    for (int i=1; i<=k; i++)
        t=min(t,kol[i-1]);
    cout<<t*k;
}