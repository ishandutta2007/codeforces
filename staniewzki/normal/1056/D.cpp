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
    
    int n;
    cin >> n;
    VI p(n);
    FOR(i, 1, n - 1)
    {
        cin >> p[i];
        p[i]--;
    }
    VI l(n);
    for(int i = n - 1; i >= 0; i--)
    {
        if(l[i] == 0)
            l[i] = 1;
        if(i != 0)
            l[p[i]] += l[i];
    } 

    sort(ALL(l));
    REP(i, n)
        cout << l[i] << " ";
}