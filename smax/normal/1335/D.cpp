#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

string grid[9];
int R[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int C[] = {0, 3, 6, 1, 4, 7, 2, 5, 8};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        for (int i=0; i<9; i++)
            cin >> grid[i];

        for (int i=0; i<9; i++) {
            int r = R[i], c = C[i];
            if (c == 8)
                grid[r][c] = grid[r][c-1];
            else
                grid[r][c] = grid[r][c+1];
        }

        for (int i=0; i<9; i++)
            cout << grid[i] << "\n";
    }

    return 0;
}