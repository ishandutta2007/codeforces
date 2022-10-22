#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,st,en) for(i=st;i<=en;i++)

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100010;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
    b =(b*b)%mod;exp/=2ll;
    }
    return res;
}

ll buc[101];
ll fac[N],inv[N];
ll dp[N],temp_dp[N];
ll ans[55][55];
string s,s1,s2;

int find(char c)
{
    if(c>='A' && c<='Z')return (int)(c-'A'+26);
    else return (c-'a');
}

inline void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
inline void sub(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,n,i,j,m,q;
    cin>>s;
    n = s.length();
    //Store the frequencies in buc
    for(int i=0;i<n;i++)buc[find(s[i])]++;
    
    //Compte factorial and inverse factorials modulo mod
    fac[0]=1;
    rep(i,1,n)fac[i]=(fac[i-1]*1ll*i)%mod;
    inv[n] = fmod(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)inv[i]=(inv[i+1]*1ll*(i+1))%mod;


    //Compute n/2! * n/2! divided by factorials of frequencies of all
    ll num = (fac[n/2]*fac[n/2])%mod;
    for(int i=0;i<52;i++)num = (num*inv[buc[i]])%mod;

    //DP for subset sum
    dp[0]=1;
    for(int i=0;i<52;i++)
    {
        if(!buc[i])continue;
        for(int j=n;j>=buc[i];j--)
            add(dp[j],dp[j-buc[i]]);
    }
    fr(i,52)ans[i][i]=dp[n/2];

    fr(i,52)
    {
        if(!buc[i])continue;
        //Temporrily store dp using all characters in an array
        for(int k=0;k<=n;k++)
            temp_dp[k]= dp[k];

        //Remove all ways consisting of the ith character from temp array
        for(int k=buc[i];k<=n;k++)
            sub(temp_dp[k],temp_dp[k-buc[i]]);
        

        for(int j=i+1;j<52;j++)
        {
            if(!buc[j])continue;
            //Now remove the jth character from the temp
            for(int k=buc[j];k<=n;k++)
                sub(temp_dp[k],temp_dp[k-buc[j]]);

            // Answer will be twice since ith and jth can be in 1st or 2nd half
            ans[i][j]= (2ll*temp_dp[n/2])%mod;
            ans[j][i]= ans[i][j]; //Symmetric
                
            //Restore condition by adding ways using jth to reset temp to without i
            for(int k=n;k>=buc[j];k--)
                add(temp_dp[k],temp_dp[k-buc[j]]);
        }
    }
    cin>>q;
    int x,y;
    while(q--)
    {
        cin>>x>>y;
        int l = find(s[x-1]);
        int r = find(s[y-1]);
        //Use precomputed num and ans, for all queries
        cout<<(num*ans[l][r])%mod<<"\n";
    }
    
    return 0;
}