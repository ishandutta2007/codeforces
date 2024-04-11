#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define flt double
#define all(a) a.begin(), a.end()

mt19937_64 rnd(1234123423424);

int n;

bool ask(const vector<int> &a) {
    cout << "? " << a.size();
    for (auto t : a) {
        cout << " " << t;
    }
    cout << endl;
    string ans;
    cin >> ans;
    return (ans == "YES");
}

bool try_to_ans(int x) {
    cout << "! " << x << endl;
    char c;
    cin >> c;
    cin >> c;
    return (c == ')');
}

vector<int> pls(const vector<int> &a, const vector<int> &b) {
    vector<int> rs;
    rs.reserve(a.size() + b.size());
    for (auto &t : a) {
        rs.push_back(t);
    }
    for (auto t : b) {
        rs.push_back(t);
    }
    return rs;
}

vector<int> pls(const vector<int> &a, const vector<int> &b,
                const vector<int> &c) {
    vector<int> rs;
    rs.reserve(a.size() + b.size() + c.size());
    for (auto &t : a) {
        rs.push_back(t);
    }
    for (auto t : b) {
        rs.push_back(t);
    }
    for (auto t : c) {
        rs.push_back(t);
    }
    return rs;
}

pair<vector<int>, vector<int>> split(const vector<int> &a) {
    vector<vector<int>> rs(2);
    for (int i = 0; i < a.size(); i += 1) {
        rs[i % 2].push_back(a[i]);
    }
    return make_pair(rs[0], rs[1]);
}

void solve3(vector<int> s) {
    int ans = ask({s[0]});
    if (ans) {
        if (try_to_ans(s[0])) {
            return;
        }
        if (ask({s[1]})) {
            try_to_ans(s[1]);
        } else {
            try_to_ans(s[2]);
        }
    } else {
        ans = ask({s[0]});
        if (ans) {
            if (try_to_ans(s[0])) {
                return;
            }
            if (ask({s[1]})) {
                try_to_ans(s[1]);
            } else {
                try_to_ans(s[2]);
            }
        } else {
            if (try_to_ans(s[1])) {
                return;
            }
            try_to_ans(s[2]);
        }
    }
}

void solve1(vector<int> s) {
    while (s.size() > 3) {
        vector<vector<int>> t(4);
        for (int i = 0; i < s.size(); i += 1) {
            t[i % 4].push_back(s[i]);
        }
        auto a0 = pls(t[0], t[2]);
        auto a1 = pls(t[0], t[1]);
        auto ans0 = ask(a0);
        auto ans1 = ask(a1);
        int bd = ans0 + (ans1 << 1);
        s.clear();
        for (int i = 0; i < 4; i += 1) {
            if (i != bd) {
                s = pls(s, t[i]);
            }
        }
    }
    if (s.size() <= 2) {
        for (auto t : s) {
            if (try_to_ans(t)) {
                return;
            }
        }
    }
    solve3(s);
}

void solve1() {
    vector<int> s(n);
    for (int i = 0; i < n; i += 1) {
        s[i] = i + 1;
    }
    solve1(s);
}


void get_goodness(vector<int> &s, vector<int> &usd, vector<int> lst_fls){
    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i < s.size(); i += 1){
        if(lst_fls[s[i]]){
            if(usd[i]){
                
            }
        }
    }
}

void solve2() {
    vector<int> s(n);
    for (int i = 0; i < n; i += 1) {
        s[i] = i + 1;
    }
    vector<int> lst_fls(n + 1, 0);
    while (s.size() > 10) {
        vector<int> usd(s.size());
        vector<int> a;
        a.reserve(s.size());
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < s.size(); i += 1) {
            if (lst_fls[s[i]]) {
                if(cnt1 % 2 == 0){
                    a.push_back(s[i]);
                    usd[i] = 1;
                }
                cnt1 += 1;
            } else{
                if(cnt2 % 2 == 0){
                    a.push_back(s[i]);
                    usd[i] = 1;
                }
                cnt2 += 1;
            }
        }
        int ans = ask(a);
        vector<int> ns;
        ns.reserve(s.size());
        for (int i = 0; i < s.size(); i += 1) {
            if (lst_fls[s[i]] && (usd[i] ^ ans)) {
                continue;
            }
            ns.push_back(s[i]);
        }
        for (int i = 0; i < s.size(); i += 1) {
            lst_fls[s[i]] = (usd[i] ^ ans);
        }
        s = ns;
    }
    solve1(s);
}

int32_t main() {
    if (0) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    cin >> n;
    solve2();
    return 0;
}