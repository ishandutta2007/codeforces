#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int m;
int g, r;
int dst[11000][1100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m;
    cin >> m;
    vector<int> safety(m);
    for (int i = 0; i < m; i++) cin >> safety[i];

    sort(safety.begin(), safety.end());

    cin >> g >> r;

    queue< pair<int, int > > q;
    queue< pair<int, int> > qn;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < g; j++) dst[i][j] = 1000000000;
    }

    dst[0][g-1] = 0;
    q.push({0, g-1});

    int curd = 0;
    long long bst = -1;

    while (!q.empty() || !qn.empty()) {
        if (q.empty()) {
            curd++;
            swap(q,qn);
        }

        pair<int, int> cur = q.front();
        q.pop();

        int loc = cur.first;
        int have_time = cur.second;
        // cout << loc << " " << have_time << " " << curd << " " << dst[cur.first][cur.second] << endl;
        
        if (curd != dst[cur.first][cur.second]) continue;
        
        if (loc == m-1) {
            long long td = dst[loc][have_time] * 1ll * (g+r);
            td += (g-1) - have_time;
            if (have_time == g-1) td -= r;

            if (bst == -1 || bst > td) {
                bst = td;
            }
        }

        if (loc != 0) {
            int d = safety[loc] - safety[loc-1];
            if (d <= have_time + 1) {
                int nd = dst[loc][have_time];
                int nt = have_time - d;

                if (nt == -1) {
                    nt = g-1;
                    nd++;
                }

                if (nd < dst[loc-1][nt]) {
                    dst[loc-1][nt] = nd;
                    if (nd == dst[loc][have_time]) q.push({loc-1,nt});
                    else qn.push({loc-1,nt});
                }
            }
        }

        if (loc != m-1) {
            int d = safety[loc+1] - safety[loc];
            if (d <= have_time + 1) {
                long long nd = dst[loc][have_time];
                int nt = have_time - d;

                if (nt == -1) {
                    nt = g-1;
                    nd ++;
                }    

                // cout << "hi " << nd << " " << dst[loc+1][nt] << endl;
                if (nd < dst[loc+1][nt]) {
                    dst[loc+1][nt] = nd;
                    if (nd == dst[loc][have_time]) q.push({loc+1,nt});
                    else qn.push({loc+1,nt});
                }
            }
        }
    }

    std::cout << bst << endl;
    return 0;
}