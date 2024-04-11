#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <vector <int> > gr;

int n;
double s;

vector <int> sz;

double res = 0;

vector <double> c;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cout.precision(20);
    cin >> n;
    cin >> s;
    if (n == 2) {
        cout << s << "\n";
        return 0;
    }
    int root = -1;
    gr.resize(n);
    c.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    int leafs = 0;
    for (int i = 0; i < n; i++) {
        if (gr[i].size() == 1) {
            leafs++;
        }
    }
    cout << 2 * s / leafs << "\n";
}