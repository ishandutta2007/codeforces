#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;


int main() {
    init();
    int n;
    string s;
    cin >> n >> s;
    s.push_back('W');
    int len = 0;
    vector <int> ans;
    for (char ch: s) {
        if (ch == 'B') len++;
        else if (len > 0) {
            ans.push_back(len);
            len = 0;
        }
    }
    cout << ans.size() << "\n";
    for (int q: ans)
        cout << q << " ";


    return 0;
}