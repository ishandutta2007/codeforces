#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "a"
void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

template<typename T>
ostream& operator << (ostream &fo, vector<T> v) {
    fo << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        fo << v[i] << " ";
    }
    fo << "] ";
    return fo;
}

template<typename T1, typename T2>
ostream& operator << (ostream &fo, pair<T1, T2> p) {
    fo << "(" << p.first << ", " << p.second << ") ";
    return fo;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)3e5 + 34;

char ss[N];

vector<int> cnt_pref(const string &s) {
    vector<int> ans = {0};
    for (int i = 0; i < (int)s.length(); i++) {
        ans.push_back(ans[i] + (int)(s[i] != 'A'));
    }
    return ans;
}

vector<int> cnt_a(const string &s) {
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'A') cur++;
        else cur = 0;
        ans.push_back(cur);
    }
    return ans;
}

void solve() {
    string s, t;
    int q, s1, f1, s2, f2;
    scanf("%s", ss);
    s = ss;
    scanf("%s", ss);
    t = ss;
    string ans;

    auto p1 = cnt_pref(s);
    auto p2 = cnt_pref(t);
    auto a1 = cnt_a(s);
    auto a2 = cnt_a(t);

    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &s1, &f1, &s2, &f2);
        s1--;
        s2--;

        int num_b1 = p1[f1] - p1[s1];
        int num_b2 = p2[f2] - p2[s2];

        int end_a1 = min(a1[f1 - 1], f1 - s1);
        int end_a2 = min(a2[f2 - 1], f2 - s2);

        bool ok = true;


        if (num_b1 == 0) {
            if (num_b2 == 0 && (end_a1 < end_a2 || (end_a1 % 3 != end_a2 % 3))) ok = false;
            if (num_b2 > 0) { num_b1 += 2; end_a1 = min(end_a1 - 1, end_a2); }
        }
        if (num_b1 % 2 != num_b2 % 2) ok = false;
        if (num_b1 > num_b2) ok = false;
        if (end_a1 < end_a2) ok = false;
        if (num_b1 == num_b2) {
            if (end_a1 < end_a2 || (end_a1 > end_a2 && end_a1 % 3 != end_a2 % 3)) ok = false;
        }

        if (ok) ans.push_back('1');
        else ans.push_back('0');
    }

    printf("%s\n", ans.c_str());
}

int main() {
    init();

    solve();

    return 0;
}