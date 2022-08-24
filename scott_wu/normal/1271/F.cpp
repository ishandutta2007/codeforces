#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[8];
int d[2][3];
int dl[2][3];
int nneed[2][8];
int gtot;

bool gtry (int nt)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 8; j++)
            nneed[i][j] = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            dl[i][j] = d[i][j];

    for (int i = 0; i < 2; i++)
    {
        int ncount = nt;
        if (i) ncount = gtot - ncount;
        for (int j = 0; j < 3; j++)
        {
            if (ncount > d[i][j])
            {
                nneed[i][7 - (1 << j)] = ncount - d[i][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 3; k++)
                if (j & (1 << k))
                    dl[i][k] -= nneed[i][j];
        }
    }

    /*for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << nneed[i][j] << " ";
        cout << "\n";
    }*/


    for (int i = 0; i < 2; i++)
    {
        int ncount = nt;
        if (i) ncount = gtot - ncount;
        for (int j = 1; j < 8; j++)
            if (j & (j - 1))
                ncount -= nneed[i][j];
        if (ncount < 0) return false;
        for (int j = 7; j >= 1; j--)
        {
            if (j & (j - 1))
            {
                while (ncount > 0 && nneed[i][j] + nneed[1-i][j] < a[j])
                {
                    nneed[i][j]++;
                    for (int k = 0; k < 3; k++)
                        if (j & (1 << k))
                            dl[i][k]--;
                    ncount--;
                }
            }
        }
    }

    /*for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << nneed[i][j] << " ";
        cout << "\n";
    }*/

    for (int i = 7; i >= 0; i--)
    {
        if (nneed[0][i] + nneed[1][i] > a[i]) return false;
        for (int j = 0; j < 2; j++)
        {
            int nc = a[i] - nneed[0][i] - nneed[1][i];
            for (int k = 0; k < 3; k++)
                if (i & (1 << k))
                    nc = min (nc, dl[j][k]);
            nneed[j][i] += nc;
            for (int k = 0; k < 3; k++)
            {
                if (i & (1 << k))
                    dl[j][k] -= nc;
            }
        }

        if (a[i] != nneed[0][i] + nneed[1][i]) return false;
    }
    return true;
}

void gogo()
{
    for (int i = 0; i < 2; i++)
        for (int j = 2; j >= 0; j--)
            cin >> d[i][j];
    for (int i = 7; i >= 1; i--)
        cin >> a[i];

    gtot = 0;
    for (int i = 1; i <= 7; i++)
        if (i & (i - 1))
            gtot += a[i];

    //gtry (7);

    for (int i = 0; i <= gtot; i++)
    {
        if (gtry (i))
        {
            for (int j = 7; j >= 1; j--)
            {
                if (j != 7) cout << " ";
                cout << nneed[0][j];
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();    
}