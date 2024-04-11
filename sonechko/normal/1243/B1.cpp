#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string t;
        cin>>t;
        vector<int> vv;
        s="."+s;
        t="."+t;
        for (int i=1; i<=n; i++)
            if (s[i]!=t[i]) vv.pb(i);
        if ((int)vv.size()==0) cout<<"Yes\n"; else
        if ((int)vv.size()==2&&s[vv[0]]==s[vv[1]]&&t[vv[0]]==t[vv[1]]) cout<<"Yes\n"; else
        cout<<"No\n";
    }
}