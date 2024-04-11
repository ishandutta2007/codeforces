#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n, k;
string s;
string t;
vector<P> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        cin >> s;
        t = "";
        for(int i = 0; i < k - 1; i++) t += "()";
        for(int i = 0; i < n / 2 - (k - 1); i++) t += "(";
        for(int i = 0; i < n / 2 - (k - 1); i++) t += ")";
        res.clear();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(s[j] == t[i]) {
                    res.push_back({i, j});
//                    cout << i << " " << j << endl;
                    reverse(s.begin() + i, s.begin() + j + 1);
//                    cout << s << endl;
                    break;
                }
            }
        }
        cout << res.size() << "\n";
        for(P p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
}