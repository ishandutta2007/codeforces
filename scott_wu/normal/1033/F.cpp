#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXW = 12;
const int MAXP = 600000;
const int MAXN = 30100;

int W, N, M;
int arr[MAXN];
int conv[(1 << MAXW)];
int nc[(1 << MAXW)];
int nv[MAXP];

int ct[MAXW][2];
int nt[MAXW];

int vc[1 << MAXW];
int nr;

void pchange (int x)
{
    for (int i = 0; i < nr; i++)
    {
        vc[i+nr+1] = vc[i];
    }
    if (nr)
    {
        int sloc = nr / 2;
        vc[sloc+nr+1] = -vc[sloc];
    }
    vc[nr] = x;
    nr = (2 * nr) + 1;
}

int res (string s)
{
    nr = 0;
    int cs = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int cp = 1;
        for (int j = i + 1; j < s.length(); j++)
            cp *= 3;

        if (s[i] == 'A')
        {
            pchange (cp);
        }
        else if (s[i] == 'O')
        {
            cs += cp * 0;
        }
        else if (s[i] == 'X')
        {
            pchange (2 * cp);
        }
        else if (s[i] == 'a')
        {
            cs += cp * 2;
        }
        else if (s[i] == 'o')
        {
            cs += cp * 1;
            pchange (cp);
        }
        else if (s[i] == 'x')
        {
            cs += cp * 1;
        }
    }

    int ans = nv[cs];
    for (int i = 0; i < nr; i++)
    {
        cs += vc[i];
        ans += nv[cs];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> W >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        nc[arr[i]]++;
    }

    for (int i = 0; i < (1 << MAXW); i++)
    {
        int cj = 0;
        for (int j = MAXW - 1; j >= 0; j--)
        {
            cj *= 3;
            if (i & (1 << j))
                cj++;
        }
        conv[i] = cj;
    }

    for (int i = 0; i < (1 << W); i++)
        for (int j = 0; j < (1 << W); j++)
            nv[conv[i]+conv[j]] += nc[i] * nc[j];

    for (int i = 0; i < M; i++)
    {
        string s; cin >> s;
        cout << res (s) << "\n";
    }
}