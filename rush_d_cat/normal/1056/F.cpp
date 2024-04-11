#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 102;
const double INF = 1e17;
int TestCas;
int n; double C,T;
struct Item {
    int a,p;
    bool operator < (const Item &o)const{
        return a>o.a;
    }
} it[N];

double dp[N][N][N*10];
double po[N];

int main() {
    po[0]=0.9; for(int i=1;i<N;i++)po[i]=po[i-1]*0.9;

    scanf("%d",&TestCas);
    while(TestCas--) {
        scanf("%d%lf%lf",&n,&C,&T);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&it[i].a,&it[i].p); sum+=it[i].p;
        }
        sort(it+1,it+1+n);

        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=sum;k++)dp[i][j][k]=INF;
            }
        }
        dp[0][0][0]=0; sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=sum;k++){
                    dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                    dp[i+1][j+1][k+it[i+1].p] = min(dp[i+1][j+1][k+it[i+1].p], dp[i][j][k]+10 + it[i+1].a / po[j]);
                }
            }
            sum += it[i+1].p;
        }
        int ans = 0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=sum;k++){
                double tmp = dp[n][j][k] - 10 * j;
                double x;
                if(C*tmp>1) x = (sqrt(C*tmp) - 1) / C;
                else x=0;
                if (x + tmp / (1+C*x) <= T - 10*j) ans = max(ans, k);
            }
        }
        cout << ans << endl;
    }
}