#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    string s;
    cin >> k >> s;

    if (k == 0) {
        int i = 0;
        long long ret = 0;
        for (int j=0; j<s.length(); j++) {
            if (s[j] == '1')
                i = j + 1;
            ret += j - i + 1;
        }
        cout << ret << "\n";
        return 0;
    }

    int i = 0, i2 = 0, sum = 0, sum2 = 0;
    long long ret = 0;
    for (int j=0; j<s.length(); j++) {
        sum += s[j] - '0';
        sum2 += s[j] - '0';
        while (sum > k)
            sum -= s[i++] - '0';
        while (sum2 > k - 1)
            sum2 -= s[i2++] - '0';
        ret += i2 - i;
    }

    cout << ret << "\n";

    return 0;
}