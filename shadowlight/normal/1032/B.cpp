#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    string s;
    cin >> s;
    int n = s.size();
    for (int d = 1; d <= 5; d++) {
        int cnt = (n - 1) / d + 1;
        if (cnt > 20) continue;
        vector <int> add(d, 0);
        int now = 0;
        while (n != cnt * d) {
            add[now]++;
            n++;
            now = (now + 1) % d;
        }
        cout << d << " " << cnt << "\n";
        int last = 0;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < cnt - add[i]; j++) {
                cout << s[last++];
            }
            for (int j = 0; j < add[i]; j++) {
                cout << "*";
            }
            cout << "\n";
        }
        return 0;
    }
}