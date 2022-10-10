#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

double dp[1001][1001][2];

double solve(int w, int b, int turn) {
    if (w == 0 || b < 0 || (b + w <= 2 && turn))
        return 0;
    if (dp[w][b][turn] < 0) {
        if (turn) { // dragon's turn
            dp[w][b][turn] = (double) b / (b + w) * w / (b + w - 1) * solve(w - 1, b - 1, !turn)
                           + (double) b / (b + w) * (b - 1) / (b + w - 1) * solve(w, b - 2, !turn);
        } else { // princess's turn
            dp[w][b][turn] = (double) w / (b + w) + (double) b / (b + w) * solve(w, b - 1, !turn);
        }
    }
    return dp[w][b][turn];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int w, b;
    cin >> w >> b;

    for (int i=0; i<=w; i++)
        for (int j=0; j<=b; j++)
            for (int k=0; k<2; k++)
                dp[i][j][k] = -1;
    cout << fixed << setprecision(10) << solve(w, b, 0) << "\n";

    return 0;
}