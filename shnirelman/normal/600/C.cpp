//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for(char c : s) {
        cnt[c - 'a']++;
    }

    int l = 0, r = 25;
    while(l < r) {
        while(l < 26 && cnt[l] % 2 == 0)
            l++;
        while(r >= 0 && cnt[r] % 2 == 0)
            r--;

        if(l < r) {
            cnt[l]++;
            cnt[r]--;
        }
    }

    string t = "";
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cnt[i] / 2; j++)
            t += char('a' + i);
    }

    cout << t;

    for(int i = 0; i < 26; i++)
        if(cnt[i] % 2)
            cout << char('a' + i);

    reverse(t.begin(), t.end());

    cout << t << endl;

}