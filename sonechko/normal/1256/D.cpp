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
    vector<int> poss;
    while (q--)
    {
        int n;
        ll k;
        cin>>n>>k;
        string s;
        cin>>s;
        s="."+s;
        int nx=-1;
        poss.clear();
        for (int i=n; i>=1; i--)
            if (s[i]=='0') poss.pb(i);
        for (int i=1; i<=n; i++)
        if (s[i]=='0') {poss.pop_back();} else
            {
                if ((int)poss.size()==0) break;
                int c=poss.back();
                if (c-i<=k)
                {
                    s[i]='0';
                    s[c]='1';
                    k-=1ll*(c-i);
                    poss.pop_back();
                }
            }
        for (int i=1; i<=n; i++)
            cout<<s[i];
        cout<<"\n";
    }
}