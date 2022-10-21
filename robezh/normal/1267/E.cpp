#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int N = 105;

int n, m;
int a[N][N];

int main() {
    cin >> m >> n;
    vector<int> res;
    for(int i = 0; i < n; i++) res.push_back(i);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
        for(int j = 0; j < m - 1; j++) a[i][j] -= a[i][m-1];
    }
    m--;
    for(int j = 0; j < m; j++) {
        vector<P> x;
        for(int i = 0; i < n; i++) {
            x.push_back({a[i][j], i});
        }
        sort(x.begin(), x.end());
        int sum = 0;

        int best_i = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(sum >= 0) {
                best_i = i;
            }
            sum += x[i].first;
        }
        if(sum >= 0) {
            best_i = -1;
        }
        vector<int> elim;
        for(int j = 0; j <= best_i; j++) elim.push_back(x[j].second);
        if(elim.size() < res.size()) {
            res = elim;
        }
    }
    cout << res.size() << endl;
    for(int x : res) cout << x + 1 << ' ';


}