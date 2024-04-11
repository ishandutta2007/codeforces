#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 1e5 + 10;
bool p[N];

bool checkPrime(int x) {
    return !p[x];
}

void init() {
    for (int i = 2; i < N; i++) {
        if (p[i]) continue;
        for (int j = i + i; j < N; j += i) {
            p[j] = true;
        }
    }
}

int n;

int queryA(int x) {
    if (x > n) return 0;
    cout << "A " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

bool used[N];

int queryB(int x) {
    if (x > n) return 0; 
    cout << "B " << x << endl;
    int cntDel = 0;
    for (int i = 1; i * x <= n; i++) {
        if (used[i * x]) continue;
        used[i * x] = true;
        cntDel++;
    }
    int ans;
    cin >> ans;
    return cntDel;
}

int outAns(int x) {
    cout << "C " << x << endl;
    exit(0);
}

void read() {
    cin >> n;
}

int ans;

void calcSmall(int x) {
    queryB(x);
    int after = queryA(x);
    if (after == 0) return;
    ans *= x;
    int a = x * x;
    while (a <= n && queryA(a)) {
        ans *= x;
        a *= x;
    }
}

void calcSmall() {
    for (int i = 2; i * i <= n; i++) {
        if (checkPrime(i)) {
            calcSmall(i);
        }
    }
}

void calcBig() {
    const int block = 95;
    vector<int> have;
    for (int i = 2; i <= n; i++) {
        if ((ll)i * i <= n) continue;
        if (checkPrime(i)) {
            have.push_back(i);
        }
    }
    int cntDel = 0;
    reverse(all(have));
    int sz = (int)have.size();
    for (int i = 0; i < sz; i += block) {
        for (int j = 0; i + j < sz && j < block; j++) {
            cntDel += queryB(have[i + j]);
        }    
        int now = queryA(1);
        if (n - cntDel == now) continue;
        for (int j = 0; i + j < sz && j < block; j++) {
            if (queryA(have[i + j])) {
                ans *= have[i + j];
                return;
            }
        }
        assert(false);
    }
}

void run() {
    ans = 1;
    calcBig();
    calcSmall();
}

void write() {
    outAns(ans);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    init();
    read();
    run();
    write();
    return 0;
}