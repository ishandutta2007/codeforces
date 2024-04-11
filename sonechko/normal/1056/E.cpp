#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int P1 = 31;
const int P2 = 29;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

string s,t;
int n;
ll st1[N],h1[N];
ll st2[N],h2[N];

inline bool good(int len1, int len2)
{
    int tt=0;
    pair<ll,ll> hh1,hh2,hh;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            int l=tt+1;
            int r=tt+len1;
            hh1.ff=((h1[r]-h1[l-1]+MOD1)*st1[n-r])%MOD1;
            hh1.ss=((h2[r]-h2[l-1]+MOD2)*st2[n-r])%MOD2;
            break;
        }
        tt+=len2;
    }
    tt=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='1')
        {
            int l=tt+1;
            int r=tt+len2;
            hh2.ff=((h1[r]-h1[l-1]+MOD1)*st1[n-r])%MOD1;
            hh2.ss=((h2[r]-h2[l-1]+MOD2)*st2[n-r])%MOD2;
            break;
        }
        tt+=len1;
    }
    if (hh1==hh2) return false;
    tt=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            int l=tt+1;
            int r=tt+len1;
            hh.ff=((h1[r]-h1[l-1]+MOD1)*st1[n-r])%MOD1;
            hh.ss=((h2[r]-h2[l-1]+MOD2)*st2[n-r])%MOD2;
            if (hh!=hh1) return false;
            tt+=len1;
        } else
        {
            int l=tt+1;
            int r=tt+len2;
            hh.ff=((h1[r]-h1[l-1]+MOD1)*st1[n-r])%MOD1;
            hh.ss=((h2[r]-h2[l-1]+MOD2)*st2[n-r])%MOD2;
            if (hh!=hh2) return false;
            tt+=len2;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>t;
    if (s.size()>t.size())
    {
        cout<<0<<endl;
        return 0;
    }
    st1[0]=P1;
    st2[0]=P2;
    t="."+t;
    n=t.size()-1;
    for (int i=1; i<=n; i++)
    {
        st1[i]=(st1[i-1]*P1)%MOD1;
        st2[i]=(st2[i-1]*P2)%MOD2;
        h1[i]=(h1[i-1]+(t[i]-'a'+1)*1ll*st1[i])%MOD1;
        h2[i]=(h2[i-1]+(t[i]-'a'+1)*1ll*st2[i])%MOD2;
    }
    int k1=0,k2=0;
    int ans=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='0') k1++; else k2++;
    for (int len1=1; len1<=n; len1++)
        if (k1*1ll*len1<n)
    {
        int len2=n-k1*len1;
        if (len2%k2!=0) continue;
        len2/=k2;
        if (good(len1, len2)) ans++;
    }
    cout<<ans<<endl;
}
/**
len_t<=1000 => len_s<=1000

max  - 1000
 


len_t>=1000
  - 1000


**/