#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

const long long P = 1000000007LL;
const long long P1 = 1000000103, Q1 = 37;
const long long P2 = 1000000181, Q2 = 61;

long long inv(long long a) {
    long long x1 = 1, b1 = a;
    long long x2 = 0, b2 = P;
    while (b2) {
        long long q = b1 / b2;
        b1 -= q * b2;
        x1 -= q * x2;
        swap(b1, b2);
        swap(x1, x2);
    }
    return ((x1 % P) + P) % P;
}

vector < int > pfunction(string s) {
    int n = (int)(s.size());
    vector < int > pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

const int maxL = 1000100;
const int maxN = 110000;
long long inv2;

int n, q;
vector < string > s;
vector < vector < pair < long long, long long > > > hf, hb;
string t;

long long cnt[26][maxN], p[maxN], ip[maxN];

long long computeCnt(int index, int l, int r) {
    long long A = cnt[index][l];
    long long B = (r >= n ? 0 : cnt[index][r + 1]);
    A -= B;
    if (A < 0) {
        A += P;
    }
    return (A * ip[n - r - 1]) % P;
}

vector < pair < long long, long long > > computeF(string& s) {
    vector < pair < long long, long long > > res(s.size());

    pair < long long, long long > cur(0, 0);
    for (int i = 0; i < s.size(); ++i) {
        cur.first = (cur.first * Q1 + s[i]) % P1;
        cur.second = (cur.second * Q2 + s[i]) % P2;
        res[i] = cur;
    }
    return res;
}

vector < pair < long long, long long > > computeB(string& s) {
    vector < pair < long long, long long > > res(s.size());

    pair < long long, long long > cur(0, 0);
    long long q1 = 1, q2 = 1;
    for (int i = s.size() - 1; i >= 0; --i, q1 = (q1 * Q1) % P1, q2 = (q2 * Q2) % P2) {
        cur.first = (cur.first + q1 * 1LL * s[i]) % P1;
        cur.second = (cur.second + q2 * 1LL * s[i]) % P2;
        res[i] = cur;
    }
    return res;
}

void precalc() {
    inv2 = inv(2);

    while (s.size() <= t.size() && s.back().size() < maxL) {
        string ns = s.back();
        ns += t[s.size() - 1];
        ns += s.back();

        s.push_back(ns);
    }
    p[0] = 1, ip[0] = 1;
    for (int i = 1; i < maxN; ++i) {
        p[i] = (p[i - 1] + p[i - 1]) % P;
        ip[i] = (ip[i - 1] * inv2) % P;
    }

    for (int i = 0; i < 26; ++i) {
        long long res = 0;
        for (int j = n - 1, q = 1; j >= 0; --j, q = (2LL * q) % P) {
            if (t[j] == 'a' + i) {
                res = (res + q) % P;
            }
            cnt[i][j] = res;
        }
    }

    hf.resize(s.size());
    hb.resize(s.size());
    for (int i = 0; i < s.size(); ++i) {
        hf[i] = computeF(s[i]);
        hb[i] = computeB(s[i]);
    }
}

void solve() {
    int index;
    string w;

    cin >> index;
    cin >> w;

    /*index = 100000;
    for (int i = 0; i < 1000000; ++i) {
        w += rand() % 2 + 'a';
    }*/

    int start = -1;
    for (int i = 0; i <= n && i <= index; ++i) {
        if (s[i].size() >= w.size()) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        start = min(n, index);
    }

    string buf = w + "#" + s[start];
    vector < int > pf = pfunction(buf);

    long long scnt = count(pf.begin(), pf.end(), w.size());

    if (index == start) {
        printf("%d\n", (int)(scnt % P));
        return;
    }

    vector < pair < long long, long long > > f, b;
    f = computeF(w);
    b = computeB(w);

    vector < long long > t(26);

    int L = s[start].size();

    for (int i = 0; i < w.size(); ++i) {
        bool ok = true;

        if (i > 0) {
            pair < long long, long long > need = f[i - 1];
            pair < long long, long long > have = hb[start][L - i];
            if (need != have) {
                ok = false;
            }
        }
        if (i + 1 < w.size()) {
            int len = w.size() - i - 1;
            pair < long long, long long > need = b[i + 1];
            pair < long long, long long > have = hf[start][len - 1];
            if (need != have) {
                ok = false;
            }
        }
        if (ok) {
            ++t[w[i] - 'a'];
        }
    }

    long long res = 0;
    for (int i = 0; i < 26; ++i) {
        res += t[i] * computeCnt(i, start, index - 1);
        res %= P;
    }

    res += scnt * p[index - start];
    res %= P;

    printf("%d\n", (int)(res));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //while (true) {

        scanf("%d%d", &n, &q);
       

        s.resize(1);
        cin >> s[0];
        cin >> t;

        /*n = 100000;
        q = 1;
        int x = rand() % 50 + 1;
        for (int i = 0; i < x; ++i) {
            s[0] += rand() % 2 + 'a';
        }
        for (int i = 0; i < n; ++i) {
            t += rand() % 2 + 'a';
        }*/

        precalc();

        for (int i = 0; i < q; ++i) {
            solve();
        }
        //cerr << "solved" << endl;
    //}


    return 0;
}