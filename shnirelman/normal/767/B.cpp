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
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    li tf, ts, t;
    cin >> ts >> tf >> t;

    int n;
    cin >> n;

    vector<li> a(n);
    map<li, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if(n == 0 || a[0] > ts) {
        cout << ts << endl;
        return 0;
    }

    li ans = a[0] - 1, res = ts - a[0] + 1;
    li cur = ts;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        li x = it->f;
        int c = it->s;

        cur += c * t;

        li t1 = cur;
        auto it1 = it;
        it1++;

        if(it1 != mp.end())
            t1 = min(t1, it1->f - 1);

        li rs = cur - t1;
        if(t1 + t <= tf && rs < res) {
            ans = t1;
            res = rs;
        }
    }

    cout << ans << endl;
}