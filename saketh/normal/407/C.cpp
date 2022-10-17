#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;
const int MAXN = 100111;

int N, M;
int ncr[MAXN][128];
int pre[128][MAXN];
int init[MAXN];

int main(){
    ios_base::sync_with_stdio(false);

    ncr[0][0] = 1;
    for(int n=1; n<MAXN; n++)
        for(int r=0; r<=100; r++){
            ncr[n][r] = ncr[n-1][r];
            if(r){
                ncr[n][r] += ncr[n-1][r-1];
                if(ncr[n][r] >= MOD) ncr[n][r] -= MOD;
            }
        }

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> pre[0][i];

    for(int i=0; i<M; i++){
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;

        pre[k+1][l]++;
        for(int j=0; j<=k; j++){
            int n = r-l+k-j, m = k-j;
            if(n<0 || m<0 || m>n) continue;
            pre[j+1][r+1] = pre[j+1][r+1] - ncr[n][m];
            if(pre[j+1][r+1] < 0) pre[j+1][r+1] += MOD;
        }
    }

    for(int K=100; K>=0; K--)
        for(int i=0; i<N; i++){
            if(i) pre[K+1][i] = pre[K+1][i] + pre[K+1][i-1];
            if(pre[K+1][i] >= MOD) pre[K+1][i] -= MOD;
            pre[K][i] = pre[K][i] + pre[K+1][i];
            if(pre[K][i] >= MOD) pre[K][i] -= MOD;
        }

    for(int i=0; i<N; i++) cout << pre[0][i] << " ";
    cout << endl;
    return 0;
}