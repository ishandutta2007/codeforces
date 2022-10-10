#include <bits/stdc++.h>
using namespace std;

string ret[1000];
unordered_map<char, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, l, k;
    string s;
    cin >> n >> l >> k >> s;

    for (char c : s)
        cnt[c]++;

    k--;
    int t = 0;
    char c = 'a';
    while (ret[k].length() < l) {
        if (cnt[c] > k - t) {
            for (int i=t; i<=k; i++)
                ret[i] += c;
            cnt[c] -= k - t + 1;
            while (c <= 'z' && cnt[c] <= 0)
                c++;
        } else {
            while (cnt[c]--)
                ret[t++] += c;
            while (c <= 'z' && cnt[c] <= 0)
                c++;
        }
    }
    for (int i=0; i<n; i++)
        while (ret[i].length() < l) {
            ret[i] += c;
            cnt[c]--;
            while (c <= 'z' && cnt[c] <= 0)
                c++;
        }

    for (int i=0; i<n; i++)
        cout << ret[i] << "\n";

    return 0;
}