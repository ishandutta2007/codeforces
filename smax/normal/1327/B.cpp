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

int ptr[100000];
bool taken[100000];
vector<int> g[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            ptr[i] = 0;
            taken[i] = false;
            g[i].clear();
        }
        for (int i=0; i<n; i++) {
            int k;
            cin >> k;
            for (int j=0; j<k; j++) {
                int x;
                cin >> x;
                g[i].push_back(x-1);
            }
        }

        int leftOver = -1;
        for (int i=0; i<n; i++) {
            while (ptr[i] < g[i].size() && taken[g[i][ptr[i]]])
                ptr[i]++;
            if (ptr[i] == g[i].size())
                leftOver = i;
            else
                taken[g[i][ptr[i]]] = true;
        }

        if (leftOver == -1) {
            cout << "OPTIMAL\n";
        } else {
            cout << "IMPROVE\n";
            for (int i=0; i<n; i++)
                if (!taken[i]) {
                    cout << leftOver + 1 << " " << i + 1 << "\n";
                    break;
                }
        }
    }

    return 0;
}