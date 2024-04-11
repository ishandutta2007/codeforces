#include <bits/stdc++.h>

#define ll long long
#define TASKNAME ""

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;

using namespace std;


int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    vector <int> data;
    vector <int> used(n + 7, 0);
    int cnt = 0;
    int next = 1;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            data.push_back(x);
        } else {
            if (!data.size() && used[next]) {
                next++;
                continue;
            }
            if (data.back() == next) {
                used[next] = 1;
                next++;
                data.pop_back();
            } else {
                cnt++;
                sort(data.begin(), data.end());
                for (int j : data) {
                    used[j] = 1;
                }
                data.clear();
                next++;
            }
        }
    }
    cout << cnt;
}