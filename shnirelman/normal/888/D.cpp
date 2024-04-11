#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);



    int n, k;
    cin >> n >> k;

    li ANS = 1;
    for(int j = 1; j <= k; j++) {
        li ans = 1;
        for(int i = n - j + 1; i <= n; i++)
            ans *= i;
        for(int i = 1; i <= j; i++)
            ans /= i;

        vector<int> p(j);
        for(int i = 0; i < j; i++)
            p[i] = i;

        int cnt = 0;
        do {
            bool res = true;
            for(int i = 0; i < j; i++)
                res &= (p[i] != i);
//            cout << "p " << res << endl;
//            for(int i = 0; i < j; i++)
//                cout << p[i] << ' ';
//            cout << endl;
            cnt += res;
        } while(next_permutation(p.begin(), p.end()));

        ANS += ans * cnt;
//        cout << ans << ' ' << cnt << endl;
    }



    cout << ANS << endl;
}