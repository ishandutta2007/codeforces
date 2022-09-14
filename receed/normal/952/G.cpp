#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    vector<string> ans(3);
    int cc = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        while (cc != s[i]) {
            cc = (cc + 255) % 256;
            ans[0] += "...";
            ans[1] += "...";
            ans[2] += ".X.";
        }
        ans[0] += "....";
        ans[1] += ".XX.";
        ans[2] += ".X..";
    }
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
}