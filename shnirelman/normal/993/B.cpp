#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = N * 30;
const int LOG = 30;




int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(2)), b(m, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i][0] >> b[i][1];
    }

    set<int> st;
    vector<set<int>> sta(n), stb(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    if(a[i][k] == b[j][l] && a[i][k ^ 1] != b[j][l ^ 1]) {
                        st.insert(a[i][k]);
                        sta[i].insert(a[i][k]);
                        stb[j].insert(b[j][l]);
                    }
                }
            }
        }
    }

    if(st.size() == 1) {
        cout << *st.begin() << endl;
        return 0;
    }

    bool fl = false;
    for(int i = 0; i < n; i++)
        if(sta[i].size() > 1)
            fl = true;

    for(int i = 0; i < m; i++)
        if(stb[i].size() > 1)
            fl = true;

    cout << (fl ? -1 : 0) << endl;
}