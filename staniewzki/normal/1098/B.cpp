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

template<class T> void db(T a) {cerr << a;}
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}";}
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    VVI table(n, VI(m));
    REP(i, n) REP(j, m)
    {
        char c;
        cin >> c;
        if(n == 1 || m == 1)
        {
            cout << c;
            if(j == m - 1)
                cout << "\n";
        }
        
        int &v = table[i][j];
        if(c == 'A') v = 0;
        if(c == 'G') v = 1;
        if(c == 'C') v = 2;
        if(c == 'T') v = 3;
    }

    if(n == 1 || m == 1)
        return 0;

    VI p = {0, 1, 2, 3};
    int mn = 1e9;
    VI best;
    int mode = -1;

    do
    {
        int sum = 0;
        REP(i, n)
        {
            int x = 0;
            REP(j, m)
                if(p[(i % 2) * 2 + j % 2] != table[i][j])
                    x++;

            int y = 0;
            REP(j, m)
                if(p[(i % 2) * 2 + (j + 1) % 2] != table[i][j])
                    y++;

            sum += min(x, y);
        }

        if(mn > sum)
        {
            best = p;
            mode = 1;
            mn = sum;
        }

        sum = 0;
        REP(i, m)
        {
            int x = 0;
            REP(j, n)
                if(p[(i % 2) * 2 + j % 2] != table[j][i])
                    x++;

            int y = 0;
            REP(j, n)
                if(p[(i % 2) * 2 + (j + 1) % 2] != table[j][i])
                    y++;
            
            sum += min(x, y);
        }

        if(mn > sum)
        {
            best = p;
            mode = 2;
            mn = sum;
        }
    }
    while(next_permutation(ALL(p)));

    V<char> alf = {'A', 'G', 'C', 'T'};
    if(mode == 1)
    {
        REP(i, n)
        {
            int x = 0;
            REP(j, m)
                if(best[(i % 2) * 2 + j % 2] != table[i][j])
                    x++;

            int y = 0;
            REP(j, m)
                if(best[(i % 2) * 2 + (j + 1) % 2] != table[i][j])
                    y++;

            REP(j, m)
                cout << alf[best[(i % 2) * 2 + (j + (y < x)) % 2]];
            cout << "\n";
        }
    }
    else
    {
        VVI ans(n, VI(m));
        REP(i, m)
        {
            int x = 0;
            REP(j, n)
                if(best[(i % 2) * 2 + j % 2] != table[j][i])
                    x++;

            int y = 0;
            REP(j, n)
                if(best[(i % 2) * 2 + (j + 1) % 2] != table[j][i])
                    y++;

            REP(j, n)
                ans[j][i] = best[(i % 2) * 2 + (j + (y < x)) % 2];
        }

        REP(i, n)
        {
            REP(j, m)
                cout << alf[ans[i][j]];
            cout << "\n";
        }
    }
}