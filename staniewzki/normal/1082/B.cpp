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

    int n;
    cin >> n;
    string str;
    cin >> str;

    int G = 0;
    REP(i, n) G += str[i] == 'G';

    int l = 0, d = 0, mx = 0;
    REP(i, n + 1)
    {
        if(i != n && str[i] == 'G')
            l++;
        else
        {
            mx = max(mx, l);
            mx = max(mx, min(l + d + 1, G));
            d = l;
            l = 0;
        }
    }

    cout << mx << "\n";
}