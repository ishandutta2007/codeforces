#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
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
    
    int q;
    cin >> q;
    REP(i, q)
    {
        auto get = [](int a)
        {
            if(a % 2 == 0)
                return a / 2; 
            if(a % 2 == 1)
                return a / 2 - a;
        };
        int l, r;
        cin >> l >> r;
        cout << get(r) - (l != 1 ? get(l - 1) : 0 ) << "\n";
    }
}