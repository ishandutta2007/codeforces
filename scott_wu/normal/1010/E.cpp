#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int XM, YM, ZM;
int N, M, K;
int X[MAXN], Y[MAXN], Z[MAXN];
int XQ[MAXN], YQ[MAXN], ZQ[MAXN];
int ans[MAXN]; // 0 for open, 1 for closed, 2 for unknown

int xlo, xhi, ylo, yhi, zlo, zhi;

int xresize (int x)
{
    if (x < xlo) return x;
    if (x <= xhi) return xlo;
    return x - (xhi - xlo);
}

int yresize (int y)
{
    if (y < ylo) return y;
    if (y <= yhi) return ylo;
    return y - (yhi - ylo);
}

int zresize (int z)
{
    if (z < zlo) return z;
    if (z <= zhi) return zlo;
    return z - (zhi - zlo);
}

vector <int> vv[MAXN];
vector <int> qv[MAXN];
map <int, int> yz;

void map_add (int x)
{
    int y = Y[x], z = Z[x];
    map<int,int>::iterator dit = yz.upper_bound(y);
    if (dit != yz.begin())
    {
        dit--;
        if (dit->second <= z)
            return;
    }

    map <int, int>::iterator it = yz.lower_bound(y);
    while (it != yz.end() && it->second >= z)
    {
        map<int,int>::iterator nit = it;
        it++;
        yz.erase (nit);
    }

    yz[y] = z;
}

void map_solve (int x)
{
    ans[x] = 2;
    int y = YQ[x], z = ZQ[x];
    map <int, int>::iterator it = yz.upper_bound(y);
    if (it != yz.begin())
    {
        it--;
        if (it->second <= z)
        {
            ans[x] = 1;
        }
    }
}

void vrun()
{
    for (int i = 0; i < MAXN; i++)
    {
        vv[i].clear();
        qv[i].clear();
    }
    yz.clear();

    for (int i = 0; i < M; i++)
    {
        if (X[i] >= 0 && Y[i] >= 0 && Z[i] >= 0)
            vv[X[i]].push_back (i);
    }
    for (int i = 0; i < K; i++)
    {
        if (XQ[i] >= 0 && YQ[i] >= 0 && ZQ[i] >= 0)
        {
            qv[XQ[i]].push_back (i);
        }
    }

    for (int i = 0; i <= XM; i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            map_add (vv[i][j]);
        }
        for (int j = 0; j < qv[i].size(); j++)
        {
            map_solve (qv[i][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> XM >> YM >> ZM >> N >> M >> K;

    xlo = 1e9, xhi = 0, ylo = 1e9, yhi = 0, zlo = 1e9, zhi = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        xlo = min (xlo, x);
        xhi = max (xhi, x);
        ylo = min (ylo, y);
        yhi = max (yhi, y);
        zlo = min (zlo, z);
        zhi = max (zhi, z);
    }

    bool bad = false;
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x = xresize (x);
        y = yresize (y);
        z = zresize (z);
        if (x == xlo && y == ylo && z == zlo)
            bad = true;

        X[i] = x - xlo;
        Y[i] = y - ylo;
        Z[i] = z - zlo;
    }

    for (int i = 0; i < K; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x = xresize (x);
        y = yresize (y);
        z = zresize (z);

        XQ[i] = x - xlo;
        YQ[i] = y - ylo;
        ZQ[i] = z - zlo;
    }

    if (bad)
    {
        cout << "INCORRECT\n";
        return 0;
    }
    cout << "CORRECT\n";

    for (int i = 0; i < 8; i++)
    {
        if (i)
        {
            for (int j = 0; j < M; j++)
            {
                if (i & 1) X[j] = -X[j];
                else if (i & 2) Y[j] = -Y[j];
                else Z[j] = -Z[j];
            }
            for (int j = 0; j < K; j++)
            {
                if (i & 1) XQ[j] = -XQ[j];
                else if (i & 2) YQ[j] = -YQ[j];
                else ZQ[j] = -ZQ[j];
            }
        }

        vrun();
    }

    for (int i = 0; i < K; i++)
    {
        if (XQ[i] == 0 && YQ[i] == 0 && ZQ[i] == 0)
            ans[i] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        if (ans[i] == 0)
        {
            cout << "OPEN\n";
        }
        else if (ans[i] == 1)
        {
            cout << "CLOSED\n";
        }
        else
        {
            cout << "UNKNOWN\n";
        }
    }
}