#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200000+10;
typedef long long LL;
int n,m;
char s[N];
int cnt[27][N],x[N],y[N],len[N];
bool ans[N];

LL p[N], inv[N], sum[27][N];

int mpow(int a, int x, int m) {
    if (x==0) return 1;
    int t = mpow(a,x>>1,m);
    if (x%2==0)
        return 1LL*t*t%m;
    return 1LL*t*t%m*a%m;
}

int hash1(int L, int R, int id, int B, int MOD) {
    int val = sum[id][R]-sum[id][L-1];
    val = (val % MOD + MOD) % MOD;
    val = 1LL * val * inv[L] % MOD;
    return val;
}

vector<int> hash2(int L,int R,int B,int MOD) {
    vector<int> ans;
    for(int i=0;i<26;i++) {
        if (cnt[i][R]-cnt[i][L-1]>0) {
            int tmp = hash1(L,R,i,B,MOD);
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

void solve(int B, int MOD) {
    p[1]=1, inv[1]=1;
    for(int i=2;i<=n;i++) 
        p[i]=1LL*p[i-1]*B%MOD, inv[i]=mpow(p[i],MOD-2,MOD);
    
    for(int i=0;i<26;i++) {
        for(int j=1;j<=n;j++) {
            sum[i][j] = sum[i][j-1] + (1LL * (s[j]=='a'+i) * p[j]);
            sum[i][j] %= MOD; 
        }
    }
    for(int i=1;i<=m;i++) {
        vector<int> ret1 = hash2(x[i],x[i]+len[i]-1, B, MOD);
        vector<int> ret2 = hash2(y[i],y[i]+len[i]-1, B, MOD);
        if (ret1 != ret2) ans[i] = 0; 
    }
}


int main() {
    scanf("%d%d%s",&n,&m,s+1);
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            cnt[j][i]=cnt[j][i-1] + ((s[i]=='a'+j)?1:0);
    
    for(int i=1;i<=m;i++) {
        ans[i] = true;
        scanf("%d%d%d",&x[i],&y[i],&len[i]);
    }

    //solve(31,1000000007);
    solve(33,1000000009);

    for(int i=1;i<=m;i++) {
        printf("%s\n", ans[i]?"YES":"NO");
    }

}