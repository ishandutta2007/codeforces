#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>

#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long li;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int main()
{
    
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    forn (i, m)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
        {
            cout << "unknown topology";
            return 0;
        }
        a--, b--;
        deg[a]++;
        deg[b]++;
    }
    int cnt2 = 0;
    int cnt1 = 0;
    int cntother = 0;
    forn (i, n)
    {
        if(deg[i] == 2)
            cnt2++;
        if(deg[i] == 1)
            cnt1++;
        if(deg[i] > 2)
            cntother++;
    }
    if(cnt2 == n)
        cout << "ring topology";
    else
        if(cnt1 == 2 && cnt2 == n - 2)
            cout << "bus topology";
        else
            if(cnt1 == n - 1 && cntother == 1)
                cout << "star topology";
            else
                cout << "unknown topology";
    return 0;
}