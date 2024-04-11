#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define MAXM 5000005
#define INF 1000000000
#define MOD 1000000007
#define MOD2 10007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};
//f**k anti-hash test!
unordered_map<int,int,custom_hash> mp[12000];
int trie[MAXM][2],tot=1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int len=j-i+1;
            if(len==1) dp[i][j]=1;
            else if(len==2) dp[i][j]=2;
            else if(len==3) dp[i][j]=4;
            else
            {
                add(dp[i][j],dp[i][j-1]);add(dp[i][j],dp[i][j-2]);add(dp[i][j],dp[i][j-3]);
                int x=a[j-3]*8+a[j-2]*4+a[j-1]*2+a[j];
                if(x!=3&&x!=5&&x!=14&&x!=15) add(dp[i][j],j-i==3?1:dp[i][j-4]);
            }
        }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int rt=1;
        for(int j=i;j>=1;j--)
        {
            if(!trie[rt][a[j]])
            {
                add(ans,dp[j][i]);
                trie[rt][a[j]]=++tot;
            }
            rt=trie[rt][a[j]];
        }
        printf("%d\n",ans);
    }
    return 0;
}