#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> A;
    vector<int> S;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.pb(x); S.pb(x);
    }
    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());
    vector<map<int, int>> answrs(n + 1);
    map<int, int> s;
    for (int i = 0; i < n; i++) {
        s[S[i]]++;
        answrs[i + 1] = s;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos;
        map<int, int> NUMS = answrs[k];
        int now = 0;
        for (auto x : A) {
            if (NUMS[x]) {
                NUMS[x]--;
                now++;
                if (now == pos) {
                    cout << x << '\n';
                    break;
                }
            }
        }
    }

}