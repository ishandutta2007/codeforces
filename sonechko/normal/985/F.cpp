#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

ll h[27][N],st[N];
int nx[27][N],n;

ll hashh(int p, int l, int r)
{
    ll hh=h[p][r]-h[p][l-1]+MOD;
    hh%=MOD;
    hh*=st[n-r];
    hh%=MOD;
    return hh;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    string s;
    cin>>s;
    s="."+s;
    st[0]=1;
    for (int j=1; j<=n; j++)
    {
        st[j]=st[j-1]*31ll;
        st[j]%=MOD;
    }
    for (int j=0; j<26; j++)
    {
        h[j][0]=0;
        ll p=1;
        for (int d=1; d<=n; d++)
        {
            if (s[d]-'a'==j) h[j][d]=h[j][d-1]+p*13;
            else h[j][d]=h[j][d-1]+p*3;
            h[j][d]%=MOD;
            p*=31;
            p%=MOD;
        }
        for (int i=n; i>=1; i--)
            if (s[i]-'a'==j) nx[j][i]=i; else nx[j][i]=nx[j][i+1];
    }
    for (int i=1; i<=m; i++)
    {
        int l,r,len;
        cin>>l>>r>>len;
        vector<pair<int,int> > v1,v2;
        for (int j=0; j<26; j++)
        {
            int p=nx[j][l];
            if (p>l+len-1) p=0;
            v1.pb(mp(p,j));
        }
        for (int j=0; j<26; j++)
        {
            int p=nx[j][r];
            if (p>r+len-1) p=0;
            v2.pb(mp(p,j));
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int ps=1;
        for (int j=0; j<v1.size(); j++)
            if (v1[j].ff==0&&v2[j].ff!=0) ps=0; else
            if (v1[j].ff!=0&&v2[j].ff==0) ps=0; else
            if (v1[j].ff==0&&v2[j].ff==0) {} else
            if (v1[j].ff-l!=v2[j].ff-r) ps=0; else
            {
                ll hh1=hashh(v1[j].ss,l,l+len-1);
                ll hh2=hashh(v2[j].ss,r,r+len-1);
                if (hh1!=hh2) ps=0;
            }
        if (ps==1) cout<<"YES\n"; else cout<<"NO\n";
    }
}