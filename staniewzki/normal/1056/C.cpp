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
    
    int n, m;
    cin >> n >> m;
    VI p(2 * n);
    REP(i, 2 * n)
        cin >> p[i];
    VI r(2 * n, -1);
    REP(i, m)
    {
        int a, b;
        cin >> a >> b;
        r[a - 1] = b - 1;
        r[b - 1] = a - 1;
    }
    int t;
    cin >> t;

    int next_obli = -1;
    REP(i, n)
    {
        if(t == 2)
        {
            int x;
            cin >> x;
            if(x == -1)
                return 0;
            x--;
            p[x] = -1;
            if(r[x] != -1 && p[r[x]] != -1)
                next_obli = r[x];
        }

        if(next_obli != -1)
        {
            cout << next_obli + 1 << "\n";
            cout.flush();
            p[next_obli] = -1;
            next_obli = -1;
        }
        else
        {
            int best = 0, second = 0;
            int max_pairing_diff = 0;
            REP(j, 2 * n)
            {
                if(p[j] == -1)
                    continue;
                if(p[j] > best)
                {
                    second = best;
                    best = p[j];
                }
                else if(p[j] > second)
                    second = p[j];

                if(r[j] != -1 && p[r[j]] != -1)
                    max_pairing_diff = max(max_pairing_diff, p[j] - p[r[j]]);
            }

            if(best - second >= max_pairing_diff)
            {
                REP(j, 2 * n)
                {
                    if(p[j] == best)
                    {
                        cout << j + 1 << "\n";
                        cout.flush();
                        p[j] = -1;
                        break;
                    }
                }
            }
            else
            {
                REP(j, 2 * n)
                {
                    if(r[j] != -1 && p[r[j]] != -1 && max_pairing_diff == p[j] - p[r[j]])
                    {
                        cout << j + 1 << "\n";
                        cout.flush();
                        p[j] = -1;
                        break;
                    }
                }
            }
        }

        if(t == 1)
        {
            int x;
            cin >> x;
            if(x == -1)
                return 0;
            x--;
            p[x] = -1; 
            if(r[x] != -1 && p[r[x]] != -1)
                next_obli = r[x];
        }
    }
}