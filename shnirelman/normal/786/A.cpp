#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using pii = pair<int, int>;

const int N = 7013;

int a[2][N];
int k[2];

//vector<int> g[2][N];
//vector<int> r[2][N];
int dp[2][N];
int cnt[2][N];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < 2; i++) {
        cin >> k[i];

        for(int j = 0; j < k[i]; j++) {
            cin >> a[i][j];
//            a[i][j]--;
        }

    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            for(int l = 0; l < k[i]; l++) {
//                g[i][j].push_back((j + a[i][l]) % n);
//                r[i ^ 1][(j + a[i][l]) % n].push_back(j);
//                cout << "edge " << i << ' ' << j << ' ' << (j + a[i][l]) % n << endl;
                cnt[i][j]++;
            }

        }
    }

    dp[0][0] = dp[1][0] = -1;
    queue<pii> q;
    q.push({0, 0});
    q.push({1, 0});
    while(!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

//        cout << i << ' ' << j << ' ' << dp[i][j] << endl;

        for(int ind = 0; ind < k[i ^ 1]; ind++) {
            int l = (j - a[i ^ 1][ind] + n) % n;
            if(dp[i][j] == -1) {
                if(dp[i ^ 1][l] == 0) {
                    dp[i ^ 1][l] = 1;
                    q.push({i ^ 1, l});
                }
            } else {
                cnt[i ^ 1][l]--;
                if(cnt[i ^ 1][l] == 0 && dp[i ^ 1][l] == 0) {
                    dp[i ^ 1][l] = -1;
                    q.push({i ^ 1, l});
                }
            }

        }

//        if(dp[i][j] == -1) {
//            for(int ind = 0; ind < k[i ^ 1]; ind++) {
//                int l = (j - a[i ^ 1][ind] + n) % n;
//                cout << i << ' ' << j << ' ' << l << endl;
//                if(dp[i ^ 1][l] == 0) {
//                    dp[i ^ 1][l] = 1;
//                    q.push({i ^ 1, l});
//                }
//            }
//
//        } else {
////            for(auto l : r[i][j]) {
//            for(int ind = 0; ind < k[i ^ 1]; ind++) {
//                int l = (j - a[i ^ 1][ind] + n) % n;
//                cout << i << ' ' << j << ' ' << l << endl;
//                cnt[i ^ 1][l]--;
//                if(cnt[i ^ 1][l] == 0 && dp[i ^ 1][l] == 0) {
//                    dp[i ^ 1][l] = -1;
//                    q.push({i ^ 1, l});
//                }
//            }
//
//        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < n; j++) {
            if(dp[i][j] == 1)
                cout << "Win ";
            else if(dp[i][j] == -1)
                cout << "Lose ";
            else
                cout << "Loop ";

        }

        cout << endl;
    }

}