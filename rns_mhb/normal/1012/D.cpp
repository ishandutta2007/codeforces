#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 250010

char s[N], t[N];
vector <pii> A, B, C, D, ans;

vector <pii> func(char *s) {
    int n = strlen(s), len = 0;
    vector <pii> ret;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i] != s[i - 1]) {
            if(len > 0) ret.push_back(pii(s[i - 1] - 'a', len));
            len = 0;
        }
        len++;
    }
    if(len > 0) ret.push_back(pii(s[n - 1] - 'a', len));
    reverse(ret.begin(), ret.end());
    return ret;
}

void go(int ca, int cb) {
    int sa = 0;
    C.clear();
    while(ca--) {
        sa += A.back().second;
        C.push_back(A.back());
        A.pop_back();
    }
    reverse(C.begin(), C.end());
    int sb = 0;
    D.clear();
    while(cb--) {
        sb += B.back().second;
        D.push_back(B.back());
        B.pop_back();
    }
    reverse(D.begin(), D.end());
    ans.emplace_back(sa, sb);
    for(auto p : C) {
        if(!B.empty() && B.back().first == p.first) B.back().second += p.second;
        else B.push_back(p);
    }
    for(auto p : D) {
        if(!A.empty() && A.back().first == p.first) A.back().second += p.second;
        else A.push_back(p);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    A = func(s);
    B = func(t);
    bool flag = 0;
    if(A.size() > B.size()) {
        swap(A, B);
        flag = 1;
    }
    if(A.size() == 1 && B.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    if(A.size() == 1) {
        int a = A.back().first;
        int b = B.back().first;
        if(a == b) go(0, B.size() / 4 * 2 + 1);
        else go(1, B.size() / 4 * 2 + 1);
    }
    else {
        int a = A.back().first;
        int b = B.back().first;
        if(a == b) {
            int d = B.size() - A.size();
            if(d % 4 == 3) go(1, 2), d = B.size() - A.size();
            go(0, d / 4 * 2 + 1);
        }
        else {
            int d = B.size() - A.size();
            if(d % 4 == 3) go(1, d / 4 * 2 + 3);
            else go(1, d / 4 * 2 + 1);
        }
    }
    while(max(A.size(), B.size()) > 1) go(1, 1);
    cout << ans.size() << endl;
    for(auto p : ans) {
        if(flag) swap(p.first, p.second);
        cout << p.first << ' ' << p.second << endl;
    }
}