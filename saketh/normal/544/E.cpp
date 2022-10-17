#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 25;
const int MLIM = 1 << 20;
typedef long long ll;

int N, M, U;
char g[MAXN][MAXN];
int p[MAXN][MAXN];
ll lc[MLIM];

int main(){
    cin >> N >> M;
    U = 1 << N;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> g[i][j];

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> p[i][j];

    memset(lc, 0x7f, sizeof(lc));
    lc[0] = 0;

    for(int c=0; c<M; c++){
        for(int r=0; r<N; r++){
            int ss = 1 << r;
            for(int m=0; m<U; m++)
               lc[m|ss] = min(lc[m|ss], lc[m] + p[r][c]); 
        }

        for(char ch='a'; ch<='z'; ch++){
            int all = 0, cst = 0;

            for(int r=0; r<N; r++)
                if(g[r][c] == ch){
                    all |= 1 << r;
                    cst += p[r][c];
                }

            for(int r=0; r<N; r++){
                if(g[r][c] == ch){
                    int cst2 = cst - p[r][c];
                    for(int m=0; m<U; m++)
                        lc[m|all] = min(lc[m|all], lc[m] + cst2);
                }
            }
        }
    }

    cout << lc[U-1] << endl;
}