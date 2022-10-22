//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

vector<int> get(string s) {
    vector<int> c(26, 0);
    for(auto x : s) {
        c[x - 'a']++;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<string> s(k);
    for(int i = 0; i < k; i++) {
        cin >> s[i];
    }

    vector<int> c = get(s[0]);
    for(int i = 1; i < k; i++) {
        if(get(s[i]) != c) {
            cout << -1 << endl;
            return 0;
        }
    }

    bool is = false;
    for(int i = 0; i < 26; i++) {
        is |= (c[i] > 1);
    }

    vector<int> cnt(k, 0);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cnt[i] += (s[i][j] != s[0][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            bool res = true;
            for(int l = 1; l < k; l++) {
                int x = cnt[l] - (s[l][i] != s[0][i]) - (s[l][j] != s[0][j]) + (s[l][i] != s[0][j]) + (s[l][j] != s[0][i]);
                if(x != 2 && (x != 0 || !is)) {
                    res = false;
                    break;
                }
            }

            if(res) {
                swap(s[0][i], s[0][j]);
                cout << s[0] << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
}