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
const int MAX = 1007;
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

Int Area(int i, int j, int k)
{
    cout << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    Int s;
    cin >> s;
    return s;
}

int vmult(int i, int j, int k)
{
    cout << 2 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    int s;
    cin >> s;
    return s;
}

Int H[MAX];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;
    int mn = 1;
    FOR(i, 2, n)
    {
        if (vmult(0, mn, i) == -1)
        {
            mn = i;
        }
    }

    FOR(i, 1, n) {
        if (i == mn)
        {
            H[i] = 0;
            continue;
        }
        H[i] = Area(0, mn, i);
    }

    int mx_id = 1;
    FOR(i,2,n)
        if (H[i] > H[mx_id])
            mx_id = i;
    vector<pair<Int, int> > L, R;

    FOR(i, 1, n)
    {
        if (i == mx_id)
            continue;
        if (vmult(0, mx_id, i) == 1)
            R.push_back(MP(H[i], i));
        else
            L.push_back(MP(H[i], i));
    }
    sort(ALL(L));
    sort(ALL(R));
    reverse(ALL(R));

    cout << "0 1";
    FOR(i,0,SZ(L))
    {
        cout << " " << L[i].second + 1;
    }
    cout << " " << mx_id + 1;
    FOR(i,0,SZ(R))
    {
        cout << " " << R[i].second + 1;
    }
    cout << endl;

}