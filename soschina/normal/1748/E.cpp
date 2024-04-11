#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 1, L = 21, p = 1e9 + 7;

int lg2[N] = {-1}, t, n, m, a[N], st[N][L];

int getpos(int l, int r){
    int d = lg2[r - l + 1];
    if(a[st[l][d]] >= a[st[r - (1 << d) + 1][d]])
        return st[l][d];
    return st[r - (1 << d) + 1][d];
}

vector<int> dp[N];

int solve(int l, int r){
    if(l > r)
        return 0;
    if(l == r){
        dp[l].resize(m + 1);
        for (int i = 1; i <= m; i++)
            dp[l][i] = i;
        return l;
    }
    int mid = getpos(l, r);
    int lmid = solve(l, mid - 1);
    int rmid = solve(mid + 1, r);
    dp[mid].resize(m + 1);
    if(mid == l){
        for (int i = 1; i <= m; i++)
            dp[mid][i] = (dp[mid][i - 1] + dp[rmid][i]) % p;
    }
    else if(mid == r){
        for (int i = 1; i <= m; i++)
            dp[mid][i] = (dp[mid][i - 1] + dp[lmid][i - 1]) % p;
    }
    else{
        for (int i = 1; i <= m; i++)
            dp[mid][i] = (dp[mid][i - 1] + 1ll * dp[lmid][i - 1] * dp[rmid][i]) % p;
    }
    return mid;
}

int main(){
    for (int i = 1; i < N; i++)
        lg2[i] = lg2[i - 1] + (i == (i & -i));
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            st[i][0] = i;
        }
        for (int j = 1; j < L; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++){
                if(a[st[i][j - 1]] >= a[st[i + (1 << (j - 1))][j - 1]])
                    st[i][j] = st[i][j - 1];
                else
                    st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
        printf("%d\n", dp[solve(1, n)][m]);
    }
	return 0;
}