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
using LL = unsigned long long;
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
    
    int n;
    cin >> n;
    VI q(101);
    REP(i, n)
    {
        int a;
        cin >> a;
        REP(j, a)
        {
            int x;
            cin >> x;
            q[x]++;
        }
    }

    REP(i, 101)
    {
        if(q[i] == n)
            cout << i << " ";
    }
}