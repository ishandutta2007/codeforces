#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int px, py;
        string s;
        cin >> px >> py >> s;
        int n = s.size();
        map<char, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }
        if (-cnt['L'] <= px && cnt['R'] >= px && -cnt['D'] <= py && cnt['U'] >= py)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}