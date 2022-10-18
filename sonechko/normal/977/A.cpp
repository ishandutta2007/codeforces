#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    int g=s.size()-1;
    for (int d=1; d<=k; d++)
    {
        if (s[g]=='0') g--; else s[g]--;
    }
    for (int p=0; p<=g; p++)
        cout<<s[p];
}