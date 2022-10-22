#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int cnt = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 5) == "Danil") {
            cnt++;
        }
        if (s.substr(i, 4) == "Olya") {
            cnt++;
        }
        if (s.substr(i, 5) == "Slava") {
            cnt++;
        }
        if (s.substr(i, 3) == "Ann") {
            cnt++;
        }
        if (s.substr(i, 6) == "Nikita") {
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}