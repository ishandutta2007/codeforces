#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int ans[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t=s;
    sort(t.begin(),t.end());
    s="."+s;
    t="."+t;
    for (int i=1; i<=n; i++)
    {
        int pos=-1;
        for (int j=1; j<=n; j++)
            if (s[j]==t[i]&&use[j]==0) {pos=j; break;}
        if (ans[pos]!=0)
        {
            for (int j=1; j<pos; j++)
                if (use[j]==0) {cout<<"NO\n"; return 0;}
        }
        if (ans[pos]==0) {ans[pos]=2;}
        use[pos]=1;
        for (int j=1; j<pos; j++)
            if (use[j]==0) ans[j]=1;
    }
    cout<<"YES\n";
    for (int i=1; i<=n; i++)
        if (ans[i]==1) cout<<"0"; else cout<<"1";
}