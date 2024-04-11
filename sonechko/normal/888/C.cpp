#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

int kol[N];
string s;
int n;
bool good(int mid)
{
    for (int i=1; i<=n-mid+1; i++)
        if (kol[i+mid-1]-kol[i-1]==0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    s='.'+s;
    int ans=n;
    for (int ii=0; ii<26; ii++)
    {
        char ch=(ii+'a');
        for (int j=1; j<=n; j++)
        {
            kol[j]=kol[j-1];
            if (s[j]==ch) kol[j]++;
        }
        if (kol[n]==0) {} else
        {
            int l=1,r=n;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (good(mid)) r=mid; else l=mid;
            }
            if (good(l)) ans=min(ans,l); else
            if (good(r)) ans=min(ans,r);
        }
    }
    cout<<ans<<endl;
}