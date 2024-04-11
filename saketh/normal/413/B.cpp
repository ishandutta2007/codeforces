#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e4 + 100;
const int MAXC = 16;

int N, M, K;
bool mem[MAXN][MAXC];
int tot[MAXC];
int sent[MAXN][MAXC];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mem[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int p, c;
        cin >> p >> c;

        tot[c-1]++;
        sent[p-1][c-1]++;
    }

    for (int i = 0; i < N; i++) {
        int ans = 0;
        for (int c = 0; c < M; c++ ) {
            if(!mem[i][c]) continue;
            ans += tot[c] - sent[i][c];
        }
        cout << ans << " ";
    }

    cout << endl;
}