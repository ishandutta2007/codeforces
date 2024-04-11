#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int ks=0;
        for (int j=0; j<s.size(); j++)
            ks+=s[j]-'0';
        int ans=1;
        if (ks%3!=0) ans=0;
        int t=0;
        for (int j=0; j<s.size(); j++)
        for (int p=0; p<s.size(); p++)
        if (j!=p&&((s[j]-'0')*10+(s[p]-'0'))%20==0) t=1;
        if (t==0) ans=0;
        if (ans==1) cout<<"red\n"; else cout<<"cyan\n";
    }
}
/**
60 = 5 * 4 * 3
**/