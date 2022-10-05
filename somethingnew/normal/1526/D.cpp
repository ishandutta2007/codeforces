#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;
            res %= mod;
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    return res;
}
int inv(int a, int mod) {
    return pow(a, mod - 2, mod);
}
int findcnk(int n, int k, int mod) {
    int res1 = 1, res2 = 1;
    if (k > n)
        return 1;
    for (int i = n - k + 1; i <= n; ++i) {
        res1 *= i;
        res1 %= mod;
        res2 *= i - n + k;
        res2 %= mod;
    }
    res1 *= inv(res2, mod);
    res1 %= mod;
    return res1;
}
pair<int, string> solve2(string s, string anot) {
    map<char, int> mpanot;
    for (int i = 0; i < 4; ++i) {
        mpanot[anot[i]] = i;
    }
    vector<int> nums(4);
    for (auto i : s)
        nums[mpanot[i]]++;
    string sres;
    for (int k = 0; k < 4; ++k) {
        string s2(nums[k], anot[k]);
        sres += s2;
    }
    int res = 0;
    for (auto i : s) {
        for (int j = 0; j < 4; ++j) {
            if (mpanot[i] > j)
                res += nums[j];
        }
        nums[mpanot[i]]--;
    }
    return {res, sres};
}
void solve(){
    string s;
    cin >> s;
    string anot = "ANOT";
    map<char, int> mp;
    mp['A'] = 0;
    mp['N'] = 1;
    mp['O'] = 2;
    mp['T'] = 3;
    sort(all(anot));
    pair<int, string> ans;
    ans.first = -3;
    do {
        ans = max(ans, solve2(s, anot));

    } while (next_permutation(all(anot)));
    cout << ans.second << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}