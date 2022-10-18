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
    string s;
    cin>>s;
    int n=s.size();
    s="."+s;
    ll ans=0;
    for (int l=1; l<=n; l++)
    {
        for (int r=l; r<=n; r++)
        {
            int p=0;
            for (int j=r-1; j>=l; j--)
            {
                int t=j-(r-j);
                if (t>=l&&s[r]==s[j]&&s[j]==s[t]) {p=1; break;}
            }
            if (p==1) {ans+=1ll*(n-r+1); break;}
        }
    }
    cout<<ans<<endl;
}
/**


**/