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
    int n;
    cin >> n;
    vector <vector <int> > all(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        all[x].push_back(i);
    }
    int last = 1;
    vector <int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int x = n - i;
        if (all[i].size() % x) {
            cout << "Impossible\n";
            return 0;
        }
        while (all[i].size()) {
            for (int j = 0; j < x; j++) {
                ans[all[i].back()] = last;
                all[i].pop_back();
            }
            last++;
        }
    }
    cout << "Possible\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}