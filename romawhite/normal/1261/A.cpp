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


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string res = "";
        FOR(i,0,k - 1)
        {
            res += "()";
        }
        FOR(i,0,n / 2 - (k - 1))
            res += "(";
        FOR(i,0,n / 2 - (k - 1))
            res += ")";
        
        vector<PII> R;
        FOR(i,0,n)
        {
            if (s[i] == res[i])
                continue;
            int j = i;
            while (s[j] != res[i]) ++j;
            R.push_back(MP(i, j));
            FOR(x,i,j + 1)
            {
                int y = j - (x - i);
                if (y <= x) break;
                swap(s[x], s[y]);
            }
        }
        cout << SZ(R) << endl;
        FOR(i,0,SZ(R))
        {
            cout << R[i].first + 1 << ' ' << R[i].second + 1 << endl;
        }
    }

    
}