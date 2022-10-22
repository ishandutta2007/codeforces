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
using pli = pair<li, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 350;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/


int x[N], y[N];
int s[N];
int lst[N];

int d[B][B];
int c[N];

pii qr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        s[i] = x[i] + y[i];
    }

    for(int i = 0; i < n; i++)
        lst[i] = -1;

    for(int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        qr[i] = {op, k};

        if(s[k] >= B) {
            if(op == 1) {
                lst[k] = i;
            } else {
                for(int j = lst[k] + x[k]; j < i; j += s[k]) {
                    c[j]++;
                    if(j + y[k] < i)
                        c[j + y[k]]--;
                    else
                        c[i]--;
                }
//                if((i - lst[k]) % s[k] >= x[k]) {
//                    c[i]--;
//                }
                lst[k] = -1;
            }
        }
    }

    for(int k = 0; k < n; k++)
        if(lst[k] != -1) {
            for(int j = lst[k] + x[k]; j < m; j += s[k]) {
                c[j]++;
                if(j + y[k] < m)
                    c[j + y[k]]--;
            }
        }

//    for(int i = 0; i < m; i++) {
//        cout << c[i] << ' ';
//    }

//    cout << endl;

    int cur = 0;
    for(int i = 0; i < m; i++) {
        int op = qr[i].f, k = qr[i].s;

        cur += c[i];

        if(s[k] < B) {
            if(op == 1) {
                lst[k] = i;
                for(int j = x[k]; j < s[k]; j++) {
                    d[s[k]][(i + j) % s[k]]++;
                }
            } else {
                for(int j = x[k]; j < s[k]; j++) {
                    d[s[k]][(lst[k] + j) % s[k]]--;
                }
            }

        } else {
//            if(op == 1) {
//                for(int j = i + x[k]; j < n; j += s[k]) {
//                    c[j]++;
//                    if(j + x[k] + y[k] < N)
//                        c[j + x[k] + y[k]]--;
//                }
//            } else {
//                for(int j = i + x[k]; j < n; j += s[k]) {
//                    c[j]++;
//                    if(j + x[k] + y[k] < N)
//                        c[j + x[k] + y[k]]--;
//                }
//            }
        }

        int res = cur;
        for(int j = 2; j < B; j++)
            res += d[j][i % j];

        cout << res << '\n';
    }


}