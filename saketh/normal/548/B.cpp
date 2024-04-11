#include <iostream>
using namespace std;

int N, M, Q;
int rlen[512];
bool bear[512][512];

int calc_row(int i){
    int len = 0, ans = 0;
    for(int j=0; j<M; j++)
        if(bear[i][j]){
            len++;
            ans = max(ans, len);
        }
        else len = 0;
    return ans;
}

int main(){
    cin >> N >> M >> Q;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cin >> bear[i][j];
        rlen[i] = calc_row(i);
    }

    for(int i=0; i<Q; i++){
        int X, Y; cin >> X >> Y; X--, Y--;
        bear[X][Y] ^= 1;
        rlen[X] = calc_row(X);
        int ans = 0;
        for(int j=0; j<N; j++) ans = max(ans, rlen[j]);
        cout << ans << "\n";
    }
}