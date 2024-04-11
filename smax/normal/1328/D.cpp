
// Problem : D. Carousel
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

const int INF = 1e9;

int t[200000], dp[200000][3][3];
pair<int, int> pred[200000][3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> t[i];
        
        // Case 1: all same type, only one color needed
        // Case 2: even length carousel, only two colors needed (just alternate colors)
        // Case 3: odd length with multiple types, just do dp
        // dp[i][j][k] - min colors used for first i, ending on color j, k+1 colors used
        for (int i=0; i<n; i++)
            for (int j=0; j<3; j++)
                for (int k=0; k<3; k++)
                    dp[i][j][k] = INF;
        dp[0][0][0] = 1;
        for (int i=1; i<n; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++) {
                    if (t[i] == t[i-1] && dp[i-1][j][k] < dp[i][j][k]) {
                        dp[i][j][k] = dp[i-1][j][k];
                        pred[i][j][k] = {j, k};
                    }
                    if (dp[i-1][j][k] + (j == 0 && k == 0) < dp[i][1-j][k+(j==0&&k==0)]) {
                        dp[i][1-j][k+(j==0&&k==0)] = dp[i-1][j][k] + (j == 0 && k == 0);
                        pred[i][1-j][k+(j==0&&k==0)] = {j, k};
                    }
                }
        
        vector<vector<int>> newDp(3, vector<int>(3));
        vector<vector<pair<int, int>>> newPred(3, vector<pair<int, int>>(3));
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++) {
                newDp[j][k] = dp[n-1][j][k];
                newPred[j][k] = pred[n-1][j][k];
            }
        if (t[0] != t[n-1]) for (int k=0; k<2; k++) {
            if (dp[n-1][0][k] >= INF) continue;
            int color = 1;
            if (t[n-1] != t[n-2] && color == pred[n-1][0][k].first)
                color = 2;
            newDp[0][k] = INF;
            newDp[color][color] = color + 1;
            newPred[color][color] = pred[n-1][0][k];
        }
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++) {
                dp[n-1][j][k] = newDp[j][k];
                pred[n-1][j][k] = newPred[j][k];
            }
        
        int jj = -1, kk = -1, best = INF;
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++)
                if (dp[n-1][j][k] < best) {
                    best = dp[n-1][j][k];
                    jj = j;
                    kk = k;
                }
        
        vector<int> v;
        for (int i=n-1; i>=0; i--) {
            v.push_back(jj + 1);
            auto p = pred[i][jj][kk];
            jj = p.first;
            kk = p.second;
        }
        reverse(v.begin(), v.end());
        
        cout << best << "\n";
        for (int c : v)
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}