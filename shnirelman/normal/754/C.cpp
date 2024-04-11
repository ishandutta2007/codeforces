//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

bool is(char c) {
    return (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9');
}

bool is(string t, string s) {
    for(int i = 0; i + s.size() <= t.size(); i++) {
        if(t.substr(i, s.size()) == s &&
            (i == 0 || is(t[i - 1])) &&
              (i + s.size() == t.size() || is(t[i + s.size()])))
           return true;
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n;

    vector<string> s(n);
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        mp[s[i]] = i;
    }



    cin >> m;

    vector<vector<bool>> can(m, vector<bool>(n, true));
    vector<int> res(m, -1);
    vector<string> t(m);
    for(int i = 0; i < m; i++) {
        string s1;
        cin >> s1;

//        cout << "--++++++++++ s1 " << s1 << endl;

        string t1 = "";

        {
            int j = 0;
            while(s1[j] != ':') {
//                cout << "while " << j << ' ' << s1[j] << endl;
                j++;
            }


            t1 = s1.substr(j + 1, s1.size() - j - 1);
//            cout << "--------t1 " << t1 << ' ' << j << endl;
            s1.erase(s1.begin() + j, s1.end());
        }

        getline(cin, t[i]);

        t[i] = t1 + t[i];

        if(s1 == "?") {
            for(int j = 0; j < n; j++)
                if(is(t[i], s[j]))
                    can[i][j] = false;
        } else {
            int ind = mp[s1];
            res[i] = ind;
            can[i] = vector<bool>(n, false);
            can[i][ind] = true;
            if(i < m - 1)
                can[i + 1][ind] = false;
            if(i > 0)
                can[i - 1][ind] = false;
        }
    }

//    cout << "--------------" << endl;
//    for(auto x : t)
//        cout << x << endl;
//    cout << "--------------" << endl;

    vector<int> cnt(m, 0);
    set<pii> st;
    for(int i = 0; i < m; i++) {
        if(res[i] == -1) {
            for(int j = 0; j < n; j++)
                cnt[i] += can[i][j];
            st.insert({cnt[i], i});
        }
    }

    while(!st.empty()) {
        int i = st.begin()->s;
        st.erase(st.begin());

//        cout << "while " << i << ' '<< cnt[i] << endl;

        if(cnt[i] == 0) {
            cout << "Impossible" << endl;
            return;
        }

        for(int j = 0; j < n; j++)
            if(can[i][j]) {
                res[i] = j;
                if(i < m - 1 && res[i + 1] == -1 && can[i + 1][j]) {
                    can[i + 1][j] = false;
                    st.erase({cnt[i + 1], i + 1});
                    cnt[i + 1]--;
                    st.insert({cnt[i + 1], i + 1});
                }

                if(i > 0 && res[i - 1] == -1 && can[i - 1][j]) {
                    can[i - 1][j] = false;
                    st.erase({cnt[i - 1], i - 1});
                    cnt[i - 1]--;
                    st.insert({cnt[i - 1], i - 1});
                }

                break;
            }
    }
//    for(int i = 0; i < m; i++)
//        cout << res[i] << ' ';
//    cout << endl;
    for(int i = 0; i < m; i++)
        cout << s[res[i]] << ':' << t[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

}