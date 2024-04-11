#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

set<int> st[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int q;
    cin>>q;
    s="."+s;
    int n=s.size()-1;
    for (int i=1; i<=n; i++)
        st[s[i]-'a'].insert(i);
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int pos;
            char c;
            cin>>pos>>c;
            st[s[pos]-'a'].erase(pos);
            s[pos]=c;
            st[s[pos]-'a'].insert(pos);
        } else
        {
            int l,r;
            cin>>l>>r;
            int ans=0;
            for (int p=0; p<26; p++)
            {
                auto it=st[p].lower_bound(l);
                if (it==st[p].end()) continue;
                int x=*it;
                if (x<=r) ans++;
            }
            cout<<ans<<"\n";
        }
    }
}