#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

string a, b, c;

bool read()
{
    if(!(cin >> a >> b >> c))
        return false;
    return true;
}

int from[102][102][102][102];

int toi(int i, int j, int len, int k)
{
    return (((((i << 7) + j) << 7) + len) << 7) + k + 1;
}

void conv(int v, int &i, int &j, int &l, int &k)
{
    v--;
    k = v & 127;
    v >>= 7;
    l = v & 127;
    v >>= 7;
    j = v & 127;
    v >>= 7;
    i = v;
}

vector<int> prefix_function (string& s)
{
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

void solve()    
{
    a += '#';
    b += '$';
    vector<int> P = prefix_function(c);
    int maxlen = 0;
    int bi, bj, bl, bk;
    forn (i, 102)
        forn (j, 102)
        forn (q, 102)
        forn (w, 102)
        from[i][j][q][w] = -1;
    from[0][0][0][0] = 0;
    forn (i, a.size())
        forn(j, b.size())
        forn (len, min(i, j) + 1)
        forn (k, c.size())
    {
        if (from[i][j][len][k] == -1)
            continue;
        if (len > maxlen)
        {
            maxlen = len;
            bi = i, bj = j, bl = len, bk = k;
        }
        if (a[i] == b[j])
        {
            int nk = k;
            while(nk > 0 && c[nk] != a[i])
                nk = P[nk - 1];
            if (c[nk] != a[i])
                nk--;
            from[i + 1][j + 1][len + 1][nk + 1] = toi(i, j, len, k);
        }
        from[i + 1][j][len][k] = from[i][j][len][k];
        from[i][j + 1][len][k] = from[i][j][len][k];
    }
    if(maxlen == 0)
        cout << 0;
    else
    {
        string ans = "";
        while(bl != 0)
        {
            int fi, fj, fl, fk;
            conv(from[bi][bj][bl][bk], fi, fj, fl, fk);
            if(fl != bl)
                ans += a[fi];
            bl = fl, bi = fi, bj = fj, bk = fk;
        }

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
    
int main()
{
  
    while(read())
        solve();
    
    return 0;
}