#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vector<int> cou(10, 0);
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            int ci = s[i] - '0';
            sum += ci;
            ++cou[ci];
        }
        if (cou[0] > 0 && cou[0] - 1 + cou[2] + cou[4] + cou[6] + cou[8] > 0 && sum % 3 == 0) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }
    return 0;
}