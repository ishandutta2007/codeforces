#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()
using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;
using VB = V<bool>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    LL n, m;
    cin >> n >> m;
    LL square = 0;
    FOR(i, 1, m) FOR(j, 1, m)
        if((i * i + j * j) % m == 0)
            square++;
    LL side = 0;
    FOR(i, 1, n % m) FOR(j, 1, m)
         if((i * i + j * j) % m == 0)
            side++;
    LL corner = 0;
    FOR(i, 1, n % m) FOR(j, 1, n % m)
        if((i * i + j * j) % m == 0)
            corner++;
    LL ans = 0;
    LL len = n / m;
    ans += len * len * square;
    ans += side * 2 * len;
    ans += corner;
    cout << ans << "\n";
}