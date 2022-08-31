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
const int A = 26;

int N, K;
string s, a, b;
int res[A];
bool used[A];
int nres[A];
int nused[A];

string yes = "YES", no = "NO";

void dilly()
{
    // assign and respond
    for (int i = 0; i < K; i++)
    {
        if (res[i] == -1)
        {
            for (int j = 0; j < K; j++)
                if (!used[j])
                {
                    res[i] = j;
                    used[j] = true;
                    break;
                }
        }
    }

    cout << yes << "\n";
    for (int i = 0; i < K; i++)
    {
        cout << (char) (res[i] + 'a');
    }
    cout << "\n";
}

bool try_high (int sstart)
{
    for (int i = 0; i < A; i++)
    {
        nres[i] = res[i];
        nused[i] = used[i];
    }

    int ss = s[sstart] - 'a', as = a[sstart] - 'a';
    if (res[ss] != -1 && res[ss] != as)
        return false;
    if (res[ss] == -1 && used[as])
        return false;
    nres[ss] = as;
    nused[as] = true;

    for (int i = sstart + 1; i < N; i++)
    {
        int av = a[i] - 'a';
        int sv = s[i] - 'a';
        if (nres[sv] != -1)
        {
            if (nres[sv] > av)
                return true;
            if (nres[sv] < av)
                return false;
        }
        else
        {
            for (int j = K - 1; j >= av; j--)
                if (!nused[j])
                {
                    nres[sv] = j;
                    nused[j] = true;
                    break;
                }
            if (nres[sv] == -1)
                return false;
            if (nres[sv] > av)
                return true;
        }
    }
    return true;
}

bool try_low (int sstart)
{
    for (int i = 0; i < A; i++)
    {
        nres[i] = res[i];
        nused[i] = used[i];
    }

    int ss = s[sstart] - 'a', bs = b[sstart] - 'a';
    if (res[ss] != -1 && res[ss] != bs)
        return false;
    if (res[ss] == -1 && used[bs])
        return false;
    nres[ss] = bs;
    nused[bs] = true;

    for (int i = sstart + 1; i < N; i++)
    {
        int bv = b[i] - 'a';
        int sv = s[i] - 'a';
        if (nres[sv] != -1)
        {
            if (nres[sv] < bv)
                return true;
            if (nres[sv] > bv)
                return false;
        }
        else
        {
            for (int j = 0; j <= bv; j++)
                if (!nused[j])
                {
                    nres[sv] = j;
                    nused[j] = true;
                    break;
                }
            if (nres[sv] == -1)
                return false;
            if (nres[sv] < bv)
                return true;
        }
    }
    return true;
}

void gogo()
{
    for (int i = 0; i < A; i++)
    {
        res[i] = -1;
        used[i] = false;
    }
    cin >> K >> s >> a >> b;

    N = s.length();
    int nstop = -1;
    for (int i = 0; i < N; i++)
    {
        int av = a[i] - 'a', bv = b[i] - 'a';
        int sv = s[i] - 'a';
        if (av == bv)
        {
            // s to a for sure
            if (res[sv] == -1 && !used[av])
            {
                res[sv] = av;
                used[av] = true;
            }

            if (res[sv] != av)
            {
                cout << no << "\n";
                return;
            }
        }
        else
        {
            // go time
            nstop = i;
            break;
        }
    }

    if (nstop == -1)
    {
        dilly();
        return;
    }
    int astop = a[nstop] - 'a', bstop = b[nstop] - 'a';
    int sstop = s[nstop] - 'a';

    int r = res[sstop];
    if (r != -1)
    {
        if (r < astop || r > bstop)
        {
            cout << no << "\n";
            return;
        }
        if (r > astop && r < bstop)
        {
            dilly();
            return;
        }
    }

    if (r == -1)
    {
        for (int i = astop + 1; i < bstop; i++)
        {
            if (!used[i])
            {
                res[sstop] = i;
                used[i] = true;
                dilly();
                return;
            }
        }
    }

    if (r == -1 || r == astop)
    {
        if (try_high (nstop))
        {
            for (int i = 0; i < A; i++)
            {
                res[i] = nres[i];
                used[i] = nused[i];
            }
            dilly();
            return;
        }
    }
    if (r == -1 || r == bstop)
    {
        if (try_low (nstop))
        {
            for (int i = 0; i < A; i++)
            {
                res[i] = nres[i];
                used[i] = nused[i];
            }
            dilly();
            return;
        }
    }
    cout << no << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    for (int test = 0; test < t; test++)
        gogo();
}