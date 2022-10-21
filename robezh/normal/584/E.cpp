#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef pair<int, int> P;

int n;
int loc[N], num[N];
int res = 0;
vector<P> ps;

void swa(int i, int j) {
    res += abs(i - j);
    ps.push_back({i, j});
    swap(num[i], num[j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        loc[a] = i;
    }
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        num[i] = loc[a];
    }
//    for(int i = 0; i < n; i++) cout << num[i];
    for(int i = n - 1; i >= 0; i--) {
        int lc;
        for(int j = 0; j < n; j++) if(num[j] == i) {
            lc = j;
            break;
        }
        for(int j = lc + 1; j <= i; j++) {
            if(num[j] <= lc) {
                swa(lc, j);
                lc = j;
            }
        }
    }
    cout << res << "\n";
    cout << ps.size() << "\n";
    reverse(ps.begin(), ps.end());
    for(auto p : ps) cout << p.first + 1 << " " << p.second + 1 << "\n";


}