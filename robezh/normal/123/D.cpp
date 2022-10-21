#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n;
string str;

struct SA {
    int n;
    // ht[i] = lcp(suffix[sa[i]], suffix[sa[i-1]])
    int rk[N], sa[N], ht[N];

    void build() {
        n = str.length() - 1;
        static int set[N], a[N];
        for(int i = 1; i <= n; i++) set[i] = str[i];
        sort(set + 1, set + n + 1);
        int *end = unique(set + 1, set + n + 1);
        for(int i = 1; i <= n; i++) a[i] = (int)(lower_bound(set + 1, end, str[i]) - set);

        static int fir[N], sec[N], tmp[N], buc[N];
        fill(buc, buc + n + 1, 0);
        for(int i = 1; i <= n; i++) buc[a[i]]++;
        for(int i = 1; i <= n; i++) buc[i] += buc[i-1];
        for(int i = 1; i <= n; i++) rk[i] = buc[a[i]-1] + 1;

        for(int t = 1; t <= n; t *= 2) {
            for(int i = 1; i <= n; i++) fir[i] = rk[i];
            for(int i = 1; i <= n; i++) sec[i] = i + t > n ? 0 : rk[i + t];

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[sec[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
            for(int i = 1; i <= n; i++) tmp[n - (--buc[sec[i]])] = i;

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[fir[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
            for(int j = 1, i; j <= n; j++) i = tmp[j], sa[buc[fir[i]]--] = i;

            bool unique = true;
            for (int j = 1, i, last = 0; j <= n; j++)
            {
                i = sa[j];
                if (!last) rk[i] = 1;
                else if (fir[i] == fir[last] && sec[i] == sec[last]) rk[i] = rk[last], unique = false;
                else rk[i] = rk[last] + 1;

                last = i;
            }

            if (unique) break;
        }

        for(int i = 1, k = 0; i <= n; i++) {
            if(rk[i] == 1) k = 0;
            else {
                if(k > 0) k--;
                int j = sa[rk[i]-1];
                while(i + k <= n && j + k <= n && a[i + k] == a[j + k]) k++;
            }
            ht[rk[i]] = k;
        }
    }
} sa;

struct P {
    int len, t;
};

struct S {
    ll sum = 0;
    int ht = 0;
    stack<P> S;

    void add(int len, int i) {
        if(len > ht) S.push({len - ht, i});
        ht = len;
        sum += ht;
    }

    void lim(int new_ht, int j) {
        if(ht <= new_ht) return ;
        while(ht > new_ht) {
            P p = S.top(); S.pop();
            ht -= p.len;
            if(ht < new_ht) {
                sum -= 1LL * (ht + p.len - new_ht) * (j - p.t);
                S.push({new_ht - ht, p.t});
                ht = new_ht;
            }
            else {
                sum -= 1LL * p.len * (j - p.t);
            }
        }
    }

} S;

int main() {
    cin >> str;
    int n = str.length();
    str = " " + str;

    sa.build();
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        if(i != 1) S.lim(sa.ht[i], i);
        S.add(n - sa.sa[i] + 1, i);
        res += S.sum;
    }
    cout << res << endl;
}