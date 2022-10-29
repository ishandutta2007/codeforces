#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string
to_string_(int x)
{
    string res;
    while (x) {
        res += x % 10 + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int
convert(string s)
{
    int res = 0;
    for (auto x : s) {
        res *= 10;
        res += x - '0';
    }
    return res;
}

int
next_val(string prev_val, string cur_val)
{
    //cout << prev_val << ' ' << cur_val << '\n';
    int n = cur_val.length();
    int prev_n = prev_val.length();
    if (n < prev_n) {
        return -1;
    } else if (n > prev_n) {
        if (cur_val[0] == '?') {
            cur_val[0] = '1';
        }
        for (int i = 1; i < n; ++i) {
            if (cur_val[i] == '?') {
                cur_val[i] = '0';
            }
        }
        return convert(cur_val);
    }
    // n == prev_n;
    int max_i = 0;
    while (max_i < n && (cur_val[max_i] == prev_val[max_i] || cur_val[max_i] == '?')) {
        ++max_i;
    }
    if (max_i == n) {
        cur_val = prev_val;
    } else if (cur_val[max_i] < prev_val[max_i]) {
        while (max_i >= 0 && (cur_val[max_i] != '?' || prev_val[max_i] == '9')) {
            --max_i;
        }
        if (max_i < 0) {
            return -1;
        }
        cur_val[max_i] = prev_val[max_i] + 1;
    }
    for (int i = 0; i <= max_i; ++i) {
        if (cur_val[i] == '?') {
            cur_val[i] = prev_val[i];
        }
    }
    for (int i = max_i; i < n; ++i) {
        if (cur_val[i] == '?') {
            cur_val[i] = '0';
        }
    }
    return convert(cur_val);
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< string > all_numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> all_numbers[i];
    }
    int cur_num = 1;
    vector< int > ans(n);
    bool ok = true;
    for (int i = 0; ok && i < n; ++i) {
        ans[i] = next_val(to_string_(cur_num), all_numbers[i]);
        if (ans[i] == -1) {
            ok = false;
        }
        cur_num = ans[i] + 1;
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}