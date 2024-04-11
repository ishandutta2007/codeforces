#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;
    VI B;
    vector<PII> A;
    FOR(i,0,n)
    {
        int x;
        cin >> x;
        A.push_back(MP(-x, i));
        B.push_back(x);
    }
    sort(ALL(A));
    vector<pair<PII, int> > Q;
    int q;
    cin >> q;
    FOR(qq,0,q)
    {
        int k, p;
        cin >> k >> p;
        Q.push_back(MP(MP(k, p), qq));
    }

    sort(ALL(Q));
    VI res(q);
    ordered_set S;
    FOR(i,0,SZ(Q))
    {
        int k = Q[i].first.first;
        int p = Q[i].first.second;
        -- p;
        while (SZ(S) < k)
        {
            int id = SZ(S);
            S.insert(A[id].second);
        }
        res[Q[i].second] = B[*S.find_by_order(p)];
    }

    FOR(i,0,SZ(res))
    {
        cout << res[i] << endl;
    }


    sort(ALL(A));


    
}