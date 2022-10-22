#define _GLIBCXX_DEBUG
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
3
vkcup
abababa
zzzzzz


1
abbbcccddd

3
abbbcccddd
aaaaaabbbc
aaaaaaabbc

1
aaaaaaabbc
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    map<char, int> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]]++;
    }

    if(mp.size() == 1) {
        cout << s << '\n';
        return;
    }

    char mn = mp.begin()->f;

    for(auto p : mp) {
        if(p.s < mp[mn]) {
            mn = p.f;
        }
    }

    if(mp[mn] == 1) {
        cout << mn;
        for(auto p : mp) {
            if(mn != p.f) {
                for(int i = 0; i < p.s; i++)
                    cout << p.f;
            }
        }

        cout << '\n';
        return;
    }
//return;
    //aa
    if(mp.begin()->s > 1) {
        char c = mp.begin()->f;

        int cnt = mp.begin()->s;

        if(n - cnt >= cnt - 2) {
            string t = "";
            t += c;
            t += c;
            mp[c] -= 2;
            if(mp[c] == 0)
                mp.erase(c);

//            cout << c << endl;
            while(!mp.empty()) {
//                cout << t << endl << mp.size() << endl;
                auto it = mp.begin();
                if(t.back() == c) {
                    if(it->f == c)
                        it++;
                } else {

                }

                char d = it->f;

                t += d;

                mp[d]--;
                if(mp[d] == 0)
                    mp.erase(d);
            }

            cout << t << '\n';
            return;
        }
    }

    auto it = mp.begin();
    char c1 = it->f;
    it++;
    char c2 = it->f;

//    cout << c1 << ' ' << c2 << endl;

    string t = "";
    t += c1;
    t += c2;

    mp[c1]--;
    mp[c2]--;

    if(mp[c1] == 0)
        mp.erase(c1);
    if(mp[c2] == 0)
        mp.erase(c2);

    while(!mp.empty()) {
        char c;
        if(mp.count(c1) && (mp.size() == 1 || (mp.size() == 2 && mp.count(c2) == 0) || mp.size() > 2)) {
            c = c1;
        } else if(mp.count(c2) && t.back() != c1) {
            c = c2;
        } else {
            auto it = mp.begin();
            while(it->f == c1 || it->f == c2)
                it++;
            c = it->f;
        }

//        cout <<"while " << c << ' ' << (mp.count('a') == 0 ? 0 : mp['a']) << endl;

        t += c;
            mp[c]--;
            if(mp[c] == 0)
                mp.erase(c);
    }

    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}