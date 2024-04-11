#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 200005

struct Book {
    int t, a, b, idx;

    bool operator < (const Book &other) const {
        return t < other.t;
    }
} book[MAXN];

int cnt[4*MAXN], st[4*MAXN];

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = book[l].t;
        cnt[p] = 1;
        return;
    }

    int m = (l + r) / 2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    st[p] = st[2*p] + st[2*p+1];
    cnt[p] = cnt[2*p] + cnt[2*p+1];
}

void update(int p, int l, int r, int idx) {
    if (l == r) {
        if (st[p]) {
            st[p] = cnt[p] = 0;
        } else {
            st[p] = book[l].t;
            cnt[p] = 1;
        }
        return;
    }

    int m = (l + r) / 2;
    if (idx <= m)
        update(2*p, l, m, idx);
    else
        update(2*p+1, m+1, r, idx);
    st[p] = st[2*p] + st[2*p+1];
    cnt[p] = cnt[2*p] + cnt[2*p+1];
}

int query(int p, int l, int r, int k) {
    if (k == 0)
        return 0;
    if (l == r)
        return st[p];

    int m = (l + r) / 2;
    if (cnt[2*p] >= k)
        return query(2*p, l, m, k);
    else
        return st[2*p] + query(2*p+1, m+1, r, k-cnt[2*p]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> book[i].t >> book[i].a >> book[i].b;
        book[i].idx = i + 1;
    }

    sort(book, book + n);
    build(1, 0, n-1);

    vector<pair<int, int>> alice, bob, both;
    for (int i=0; i<n; i++) {
        if (book[i].a && book[i].b)
            both.emplace_back(book[i].t, i);
        else if (book[i].a)
            alice.emplace_back(book[i].t, i);
        else if (book[i].b)
            bob.emplace_back(book[i].t, i);
    }

    int ret = INT_MAX, retIdx = -1, retA = -1, retB = -1, retT = -1, aCnt = 0, bCnt = 0, ptrA = 0, ptrB = 0, cur = 0, tot = 0;
    for (int i=0; i<=min((int) both.size(), m); i++) {
        while (aCnt < k && ptrA < alice.size()) {
            aCnt++;
            tot++;
            cur += alice[ptrA].first;
            update(1, 0, n-1, alice[ptrA].second);
            ptrA++;
        }
        while (bCnt < k && ptrB < bob.size()) {
            bCnt++;
            tot++;
            cur += bob[ptrB].first;
            update(1, 0, n-1, bob[ptrB].second);
            ptrB++;
        }
        while (aCnt > k && ptrA - 1 >= 0) {
            aCnt--;
            tot--;
            ptrA--;
            cur -= alice[ptrA].first;
            update(1, 0, n-1, alice[ptrA].second);
        }
        while (bCnt > k && ptrB - 1 >= 0) {
            bCnt--;
            tot--;
            ptrB--;
            cur -= bob[ptrB].first;
            update(1, 0, n-1, bob[ptrB].second);
        }
        if (tot <= m && aCnt >= k && bCnt >= k) {
            int calc = cur + query(1, 0, n-1, m-tot);
            if (calc < ret) {
                ret = calc;
                retIdx = i;
                retA = ptrA;
                retB = ptrB;
                retT = tot;
            }
        }
        if (i < both.size()) {
            aCnt++;
            bCnt++;
            tot++;
            cur += both[i].first;
            update(1, 0, n-1, both[i].second);
        }
    }

    if (retIdx == -1)
        cout << "-1\n";
    else {
        cout << ret << "\n";
        set<int> st;
        for (int i=0; i<retIdx; i++)
            st.insert(book[both[i].second].idx);
        for (int i=0; i<retA; i++)
            st.insert(book[alice[i].second].idx);
        for (int i=0; i<retB; i++)
            st.insert(book[bob[i].second].idx);
        for (int i=0; i<n && m-retT; i++)
            if (!st.count(book[i].idx)) {
                st.insert(book[i].idx);
                retT++;
            }
        for (int x : st)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}