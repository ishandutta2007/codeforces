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
const int MAXN = 200100;
const int MAXS = 4000;

int N, f;
int sg[MAXN];
bool sp[MAXN];
vector <int> gval[MAXS];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++) sp[i] = false;

    for (int i = 2; i < MAXN; i++)
    {
        int nfac = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
                nfac++;
            if (i % (j * j) == 0 && i > j * j)
                nfac += 10;
        }
        if (nfac <= 1)
        {
            sp[i] = true;
        }
    }

    cin >> N >> f;
    sp[f] = false;
    sg[0] = 0;
    gval[0].push_back(0);

    for (int i = 1; i < MAXN; i++)
    {
        //cout << i << " YO" << endl;
        int res = 0;
        while (true)
        {
            if (!gval[res].size()) break;
            bool found = false;

            int r = gval[res].size() - 1;
            int ss = max (0, r - 1000);
            int st = min (1000, ss);
            for (int j = r; j >= ss; j--)
            {
                int nd = i - gval[res][j];
                if (sp[nd])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            for (int j = 0; j < st; j++)
            {
                int nd = i - gval[res][j];
                if (sp[nd])
                {
                    found = true;
                    break;
                }
            }

            if (!found) break;
            res++;
        }
        sg[i] = res;
        gval[res].push_back(i);
    }

    int mm = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mm ^= sg[b - a - 1];
        mm ^= sg[c - b - 1];
    }
    if (mm)
    {
        cout << "Alice\nBob\n";
    }
    else
    {
        cout << "Bob\nAlice\n";
    }
}