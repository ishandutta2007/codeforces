#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXV = 1028;

int N, M;
int grid[MAXV][MAXV];
int seen[MAXV][MAXV];

int R;
bool check(int lim) {
    R++;
    for (int i = 0; i < N; i++) {
        vector<int> js;
        for (int j = 0; j < M; j++) {
            if(grid[i][j] < lim) continue;
            for (int oj : js)
                if(seen[oj][j] == R) return true;
                else seen[oj][j] = R;
            js.push_back(j);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    int lo = 0, hi = 1e9;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if(check(mi)) {
            ans = mi;
            lo = mi + 1;
        }
        else hi = mi - 1;
    }

    cout << ans << endl;
}