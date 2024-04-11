#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);



    string s;
    cin >> s;

    int n = s.size();

    int l = 0, r = n;
    while(r - l > 1) {
        vector<int> cnt(A, 0);
        vector<bool> is(A, true);

        int m = (l + r) / 2;
        for(int i = 0; i < m; i++) {
            cnt[s[i] - 'a']++;
        }

        for(int i = 0; i < A; i++) {
            is[i] = (cnt[i] > 0);
        }

        for(int i = 0; i + m < n; i++) {
            cnt[s[i] - 'a']--;
            cnt[s[i + m] - 'a']++;

            if(cnt[s[i] - 'a'] == 0)
                is[s[i] - 'a'] = false;
        }

        bool fl = false;
        for(int i = 0; i < A; i++)
            fl |= is[i];

        if(fl)
            r = m;
        else
            l = m;
    }

    cout << r << endl;
}