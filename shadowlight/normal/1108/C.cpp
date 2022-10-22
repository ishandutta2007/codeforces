#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map <char, int> num;
    num['R'] = 0;
    num['G'] = 1;
    num['B'] = 2;
    string t = "RGB";
    vector <int> a = {0, 1, 2};
    int mink = INF;
    vector <int> res;
    do {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (num[s[i]] != a[i % 3]) {
                cnt++;
            }
        }
        if (cnt < mink) {
            mink = cnt;
            res = a;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << mink << "\n";
    for (int i = 0; i < n; i++) {
        cout << t[res[i % 3]];
    }
}