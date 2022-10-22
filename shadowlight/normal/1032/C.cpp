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
    int last;
    cin >> last;
    vector <int> a(n);
    vector <vector <int> > pr(n, vector <int> (5, -1));
    for (int i = 0; i < 5; i++) {
        pr[0][i] = INF;
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 5; j++) {
            if (pr[i - 1][j] == -1) continue;
            for (int k = 0; k < 5; k++) {
                if (x > last && k > j) {
                    pr[i][k] = j;
                } else if (x < last && k < j) {
                    pr[i][k] = j;
                } else if (x == last && k != j) {
                    pr[i][k] = j;
                }
            }
        }
        last = x;
    }
    int st = -1;
    for (int i = 0; i < 5; i++) {
        if (pr[n - 1][i] != -1) {
            st = i;
            break;
        }
    }
    if (st == -1) {
        cout << -1;
        return 0;
    }
    vector <int> res;
    int now = n - 1;
    while (st != INF) {
        res.push_back(st);
        st = pr[now][st];
        now--;
    }
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}