#include <bits/stdc++.h>
using namespace std;
typedef complex<double> C;
typedef vector<double> vd;
typedef pair<int, int> ii;
double T_PI = 2.0*acos(-1);

void fft(vector<C> &f) {
    int n = f.size(), l = __lg(n);
    if(n == 1)
        return;
    vector<int> rev(n);
    vector<C> rt(n);
    for(int i = 0; i < n/2; i++)
        rt[i + n/2] = polar(1.0, (T_PI * i)/n);
    for(int i = n/2 - 1; i >= 1; i--)
        rt[i] = rt[2*i];
    for(int i = 1; i < n; i++)
        rev[i] = rev[i / 2] / 2 + ((i & 1) << (l - 1));
    for(int i = 0; i < n; i++)
        if(rev[i] < i)
            swap(f[i], f[rev[i]]);
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                C z = f[i + j + k] * rt[k + j];
                f[i + j + k] = f[i + j] - z;
                f[i + j] += z;
            }
        }
    }
}

vd conv(vd A, vd B) {
    int sz = A.size() + B.size() - 1, n = 1 << (__lg(sz - 1) + 1);
    vd res(sz);
    vector<C> a(n), b(n);
    for(int i = 0; i < A.size(); i++)
        a[i].real(A[i]);
    for(int i = 0; i < B.size(); i++)
        b[i].real(B[i]);
    fft(a);
    fft(b);
    for(int i = 0; i < n; i++)
        a[i] *= b[i];
    reverse(a.begin() + 1, a.end());
    fft(a);
    for(int i = 0; i < sz; i++)
        res[i] = (a[i].real() / n);
    return res;
}

const int MAXN = 13e4;
vector<ii> edg[MAXN];
int rep[10], cnt[MAXN][6];

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

int join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return 0;
    rep[v] = u;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++) {
        for(int ch = 0; ch < 6; ch++)
            cnt[i][ch] = (i ? cnt[i - 1][ch] : 0);
        cnt[i][s[i] - 'a']++;
    }
    reverse(t.begin(), t.end());

    for(int ch1 = 0; ch1 < 6; ch1++) {
        vd A(s.size());
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'a' + ch1)
                A[i]++;
        for(int ch2 = 0; ch2 < 6; ch2++) {
            if(ch1 == ch2)
                continue;
            vd B(t.size());
            for(int i = 0; i < t.size(); i++)
                if(t[i] == 'a' + ch2)
                    B[i]++;
            auto C = conv(A, B);
            int off = (int)t.size() - 1;
            for(int i = off; i < s.size(); i++) {
                if(C[i] > 0.5)
                    edg[i - off].push_back({ch1, ch2});
            }
        }
    }
    for(int i = 0; i + t.size() <= s.size(); i++) {
        memset(rep, -1, sizeof rep);
        int ans = 0;
        for(auto e : edg[i])
            ans += join(e.first, e.second);
        cout << ans << " ";
    }
    cout << '\n';
}