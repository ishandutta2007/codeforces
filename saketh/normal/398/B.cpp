#include <iostream>
using namespace std;

const int MAXN = 2048;

int N, M; double NN;
double ans[MAXN][MAXN];
double fra[MAXN], frb[MAXN][MAXN];
bool pr[MAXN], pc[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    NN = N;

    for(int i=0; i<=N; i++)
        fra[i] = i/NN;

    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++)
            frb[i][j] = fra[i] * fra[j];

    ans[0][0] = 0;
    for(int ur=0; ur<=N; ur++)
        for(int uc=0; uc<=N; uc++){
            if(!(ur+uc)) continue;
            double stay = frb[N-ur][N-uc];
            double rhs = 1;
            if(ur) rhs += frb[ur][N-uc] * ans[ur-1][uc];
            if(uc) rhs += frb[N-ur][uc] * ans[ur][uc-1];
            if(ur && uc) rhs += frb[ur][uc] * ans[ur-1][uc-1];
            ans[ur][uc] = rhs / (1 - stay);
        }
   
    int UR = N, UC = N;

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        if(!pr[x-1]){ pr[x-1] = true; UR--; }
        if(!pc[y-1]){ pc[y-1] = true; UC--; }
    }

    cout.precision(20);
    cout << ans[UR][UC] << endl;
    return 0;
}