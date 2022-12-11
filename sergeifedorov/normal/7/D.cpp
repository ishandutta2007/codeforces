#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const int nmax = 5*1000*1001;

char s[nmax*2];
int p[nmax*2];

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(outp.data(),"wt", stdout);

    gets(s);
    int n = strlen(s);
    s[n] = '#';
    forn(i,n)
        s[2*n-i] = s[i];
    int len = 2*n+1;
    p[0] = 0;
{   int l = 0, r = 0;
    for (int i=1; i<len; ++i)
        if (p[i-l]+i <= r)
            p[i] = p[i-l];
        else
        {
            l = i;
            if (i > r) r = i;
            for (p[i] = r-i; r<len; ++r, ++p[i])
                if (s[r] != s[p[i]])
                    break;
            --r;
        }
}
    int res = 1;
    p[0] = 1;
    for (int i = 1; i < n; i++){

        p[i] = 0;
        int j = 2*n - i;
        if (p[j] < (i+1)/2)
            continue;
        p[i] = p[(i-1)/2] + 1;
        res += p[i];
    }
    cout << res << endl;

    return 0;
}