#include <iostream>
using namespace std;

const int N = 102;
const int MOD = 1e9 + 7;

int n,a[N],b[N];
int dp[2][N][N*N];
int c[N][N];
void init() {
    for(int i=0;i<N;i++) c[i][0]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
        }
    }
}
int main() {
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);b[a[i]] ++;
    }

    dp[1][0][0]=1;int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=sum;k++){
                dp[0][j][k]=dp[1][j][k]; dp[1][j][k]=0;
            }
        }
        for(int j=0;j<=i;j++){
            for(int k=0;k<=sum;k++){
                (dp[1][j][k] += dp[0][j][k]) %= MOD;
                (dp[1][j+1][k+a[i+1]] += dp[0][j][k]) %= MOD;
            }
        }
        sum += a[i+1];
    }

    int cnt=0;
    for(int i=1;i<=100;i++)if(b[i])cnt++;
    if(cnt<=2) {
        printf("%d\n", n); return 0;
    }

    //printf("%d %d\n", dp[1][2][2], c[2][2]);
    int ans = 0;
    for(int i=1;i<=100;i++) {
        for(int j=1;j<=b[i];j++){
            int sum = j * i;
            int c1 = dp[1][j][sum];
            int c2 = c[b[i]][j];
            if (c1 == c2) ans = max(ans, j);
        }
    }
    printf("%d\n", ans);
}