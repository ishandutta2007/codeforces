#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 500 + 13;
const int LOGN = 20;
const int A = 27;

bool isp(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int d[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    if(isp(n)) {
        cout << 1 << endl << n << endl;
        return 0;
    }

    if(isp(n - 2)) {
        cout << 2 << endl << 2 << ' '<< n - 2 << endl;
        return 0;
    }

    vector<int> p;
    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            p.push_back(i);
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    random_shuffle(p.begin(), p.end());

    for(auto x : p) {
        for(auto y : p) {
            if(isp(n - x - y)) {
                cout << 3 << endl << x << ' ' << y << ' ' << n - x - y << endl;
                return 0;
            }
        }
    }
}