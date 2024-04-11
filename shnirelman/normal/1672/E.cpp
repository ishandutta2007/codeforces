#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 30;
const int L = 2001;

int cnt = 0;
vector<int> A = {5, 2, 7, 3, 5, 6};

map<int, int> mem;

//int query(int w) {
//    if(mem.count(w))
//        return mem[w];
//
//    cnt++;
//
//    if(*max_element(A.begin(), A.end()) > w)
//        return mem[w] = 0;
//
//    int res = 0;
//    for(int i = 0; i < A.size(); ) {
//        int j = i + 1;
//        int cur = A[i];
//        while(j < A.size() && cur + 1 + A[j] <= w) {
//            if(w == 33) {
//                cout << "--------------- " << i << ' ' << j << ' ' << cur << ' ' << cur + 1 + A[j] << endl;
//            }
//
//            cur += 1 + A[j];
//            j++;
//        }
//        i = j;
//        res++;
//    }
//
//    cout << "query " << w << ' ' << res << endl;
//
//    return mem[w] = res;
//}


int query(int w) {
    if(mem.count(w))
        return mem[w];

    cout << "? " << w << endl;
    int res;
    cin >> res;

    return mem[w] = res;
}

void answer(int x) {
    cout << "! " << x << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    int l = 0, r = n * L + n;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int h = query(m);

//        cout << "bin search " << l << ' ' << m << ' ' << r << endl;

        if(h == 0 || h >= 2)
            l = m;
        else
            r = m;
    }

//    cout << "r = " << r << endl;

    int s = r - n + 1;
    int ans = r;

//    cout << "sum = " << s << endl;
//    cout << "cnt = " << cnt << endl;

    for(int x = 0; x < n - 1; x++) {
        for(int h = 1; h <= n; h++) {
            if(n - h <= x && (s + x) % h == 0) {
                int w = (s + x) / h;
                int h1 = query(w);

                if(h1 != 0)
                    ans = min(ans, w * h1);
            }
        }
    }

//    cout << "cnt = " << cnt << endl;

    answer(ans);

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}