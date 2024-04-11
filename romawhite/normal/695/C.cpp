#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))
#define MP make_pair
#define PB push_back
#define ALL(A) A.begin(),A.end()
#define SZ(A) (int)A.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000000;
const int MAX = 1007;
const int ST = 1000000007;

struct Point
{
    int x , y;
    Point(int _x , int _y) : x(_x) , y(_y) {}
    Point(){}
};

bool inSegment(Point x , Point a , Point b)
{
    Int vm = 1LL * (a.x - x.x) * (b.y - x.y) - 1LL * (a.y - x.y) * (b.x - x.x);
    if (vm != 0) return 0;
    if (x.x < min(a.x , b.x)) return 0;
    if (x.x > max(a.x , b.x)) return 0;
    if (x.y < min(a.y , b.y)) return 0;
    if (x.y > max(a.y , b.y)) return 0;

    return 1;
}

Point A[MAX];
Point B[MAX];

VI C[8][MAX];

int k , n;

bool F(int mask, set<int> killed , set<int> nx)
{
    if (SZ(nx) == 0) return 1;
    if (SZ(nx) + __builtin_popcount(mask) > k) return 0;

    int id = *nx.begin();
    nx.erase(id);

    killed.insert(id);

    FOR(i,0,k)
    {
        if (mask & (1 << i)) continue;

        if (SZ(C[i][id]) >= k) continue;

        set<int> nx2 = nx;
        FOR(j,0,SZ(C[i][id]))
        {
            if (killed.find(C[i][id][j]) == killed.end())
            {
                nx2.insert(C[i][id][j]);
            }
        }

        if (F(mask | (1 << i) , killed , nx2)) return 1;

    }

    return 0;

}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    cin >> k >> n;
    //k = 7;
    //n = 1000;

    FOR(i,0,k)
    {
        cin >> A[i].x >> A[i].y;
        //A[i].x = rand();
        //A[i].y = rand();
    }

    FOR(i,0,n)
    {
        cin >> B[i].x >> B[i].y;
        //B[i].x = rand();
        //B[i].y = rand();
    }

    FOR(i,0,k)
    {
        FOR(j,0,n)
        {
            FOR(t,0,n)
            {
                if (t == j) continue;
                if (inSegment(B[t] , A[i] , B[j]))
                {
                    C[i][j].push_back(t);
                    //cout << i << ' ' << j << ' ' << t << endl;
                }
            }
        }
    }

    int res = 0;

    FOR(i,0,n)
    {
        set<int> nx;
        nx.insert(i);
        if (F(0,set<int>() , nx))
            ++ res;
    }

    cout << res << endl;

    return 0;
}