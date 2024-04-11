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
const int N = 100000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

vector<int> dv[N];
int d[N];
int cnt[N], a[N];
int pw[N];

int get(int x) {
//    cout << "get " << x << endl;
    int res = 1;
    while(x > 1) {
//        cout << x << endl;
        res *= -1;
        int y = d[x];
        x /= y;
        if(x % y == 0)
            return 0;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            dv[j].push_back(i);
        }
    }

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    pw[0] = 1;
    for(int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 2ll % M;
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        for(auto x : dv[a[i]])
            cnt[x]++;
    }

    int res = 0;
    for(int i = 1; i < N; i++) {

        res = (res + get(i) * 1ll * (pw[cnt[i]] + M - 1)) % M;
    }

    cout << res << endl;
}