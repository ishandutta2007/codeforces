#include <iostream>
using namespace std;

const int MAXN = 1024;
const int INF = 0x3fffffff;

int N, g[MAXN][MAXN], m[MAXN][MAXN], w[MAXN][MAXN];
int ans = INF, zx = -1, zy = -1;

void print(int i, int j){
    if(!i && !j) return;
    if(w[i][j] == 0){ print(i-1, j); cout << "D"; }
    else { print(i, j-1); cout << "R"; }
}

int calc(int f, bool disp){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int here = 0;
            for(int tmp = g[i][j]; tmp%f==0; tmp/=f) here++;
            if(!i && !j){ m[i][j] = here; continue; }

            m[i][j] = INF;
            if(i>0 && (m[i-1][j]+here < m[i][j])){
                m[i][j] = m[i-1][j] + here;
                w[i][j] = 0;
            }
            if(j>0 && (m[i][j-1]+here < m[i][j])){
                m[i][j] = m[i][j-1] + here;
                w[i][j] = 1;
            }
        }

    if(disp){ print(N-1, N-1); cout << endl; }
    return m[N-1][N-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> g[i][j];
            if(!g[i][j]){
                ans = 1;
                g[i][j] = 10;
                zx = i;
                zy = j;
            }
        }

    int c2 = calc(2, false), c5 = calc(5, false);
    ans = min(ans, min(c2, c5));
    cout << ans << endl;
    
    if(ans == 1 && zx != -1){
        for(int i=0; i<zx; i++) cout << "D";
        for(int j=0; j<zy; j++) cout << "R";
        for(int i=zx; i+1<N; i++) cout << "D";
        for(int j=zy; j+1<N; j++) cout << "R";
        cout << endl;
        return 0;
    }
    else if(ans == c2) calc(2, true);
    else calc(5, true);
    return 0;
}