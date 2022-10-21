#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = (int)1e9;

int x[3], y[3];
bool on[N][N];
bool ocu[N][N];

int main(){
    for(int i = 0; i < 3; i++) cin >> x[i] >> y[i], on[x[i]][y[i]] = true;
    int px = 0, py = 0, ans = INF;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cur = 0;
            for(int t = 0; t < 3; t++){
                cur += abs(i - x[t]) + abs(j - y[t]);
            }
            cur ++;
            if(cur < ans) {
                px = i, py = j;
                ans = cur;
            }
        }
    }
//    cout << px << " " << py << endl;
    printf("%d\n", ans);
    for(int t = 0; t < 3; t++){
        for(int i = min(x[t], px); i <= max(x[t], px); i++) ocu[i][py] = true;
        for(int j = min(y[t], py); j <= max(y[t], py); j++) ocu[x[t]][j] = true;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(ocu[i][j]) printf("%d %d\n", i, j);
        }
    }
}