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
    int q;
    cin>>q;
    for (int jj=1; jj<=q; jj++)
    {
        string s;
        string t;
        cin>>s>>t;
        int k=0;
        for (int p=0; p<s.size(); p++)
        for (int d=0; d<t.size(); d++)
            if (s[p]==t[d]) k++;
        if (k>0) cout<<"YES\n"; else cout<<"NO\n";
    }
}