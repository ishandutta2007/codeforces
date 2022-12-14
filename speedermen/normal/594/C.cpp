#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, k;
vector < pair < pair < int, int >, int > > ptsX, ptsY;
multiset < pair < int, int > > X, Y;
int x[N][2], y[N][2];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
    }
    long long ans = 8e18;
    for (int it = 0; it < 2; ++it) {
        ptsX.clear();
        ptsY.clear();
        X.clear();
        Y.clear();
        for (int i = 1; i <= n; ++i) {
            ptsX.push_back(make_pair(make_pair(x[i][0] + x[i][1], y[i][0] + y[i][1]), i));
            ptsY.push_back(make_pair(make_pair(y[i][0] + y[i][1], x[i][0] + x[i][1]), i));
            X.insert(ptsX[i - 1].first);
            Y.insert(ptsY[i - 1].first);
        }
        sort(ptsX.begin(), ptsX.end());
        sort(ptsY.begin(), ptsY.end());
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; i + j <= k; ++j) {
                for (int li = 0; li < i; ++li) {
                    X.erase(X.find(make_pair(ptsX[li].first.first, ptsX[li].first.second)));
                    Y.erase(Y.find(make_pair(ptsX[li].first.second, ptsX[li].first.first)));
                }
                for (int li = 0; li < j; ++li) {
                    X.erase(X.find(make_pair(ptsX[n - 1 - li].first.first, ptsX[n - 1 - li].first.second)));
                    Y.erase(Y.find(make_pair(ptsX[n - 1 - li].first.second, ptsX[n - 1 - li].first.first)));
                }
                int have = k - (i + j);
                for (int ii = 0; ii <= have; ++ii) {
                    for (int jj = 0; jj + ii <= have; ++jj) {
                        vector < pair < int, int > > ins;
                        int di = ii, dj = jj;
                        while (di > 0) {
                            ins.push_back(*Y.begin());
                            Y.erase(Y.begin());
                            --di;
                        }
                        while (dj > 0) {
                            ins.push_back(*--Y.end());
                            Y.erase(--Y.end());
                            --dj;
                        }
                        for (int l = 0; l < ins.size(); ++l) {
                            X.erase(X.find(make_pair(ins[l].second, ins[l].first)));
                        }
                        ans = min(ans, 1LL * max((X.rbegin()->first - X.begin()->first + 1) / 2, 1) * max((Y.rbegin()->first - Y.begin()->first + 1) / 2, 1));
                        for (int l = 0; l < ins.size(); ++l) {
                            X.insert(make_pair(ins[l].second, ins[l].first));
                            Y.insert(ins[l]);
                        }
                    }
                }
                for (int li = 0; li < i; ++li) {
                    X.insert(make_pair(ptsX[li].first.first, ptsX[li].first.second));
                    Y.insert(make_pair(ptsX[li].first.second, ptsX[li].first.first));
                }
                for (int li = 0; li < j; ++li) {
                    X.insert(make_pair(ptsX[n - 1 - li].first.first, ptsX[n - 1 - li].first.second));
                    Y.insert(make_pair(ptsX[n - 1 - li].first.second, ptsX[n - 1 - li].first.first));
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            swap(x[i][0], y[i][0]);
            swap(x[i][1], y[i][1]);
        }
    }
    cout << ans << endl;
    return 0;
}