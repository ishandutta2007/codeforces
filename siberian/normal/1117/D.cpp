#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector <vector <int> > matrix;
const int MOD = 1e9 + 7;
int n, m;
void read()
{
    cin >> n >> m;
}

matrix mul(matrix a, matrix b)
{
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    matrix c(n, vector <int> (k, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int t = 0; t < m; t++)
            {
                c[i][j] += a[i][t] * b[t][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

matrix binpow(matrix a, int n)
{
    if (n <= 1)
        return a;
    if (n % 2 == 0)
    {
        matrix x = binpow(a, n / 2);
        return mul(x, x);
    }
    else
    {
        matrix x = binpow(a, n - 1);
        return mul(a, x);
    }
}

void run()
{
    matrix a(m, vector <int> (m));
    a[0][0] = 1;
    a[0][m - 1] = 1;
    for (int i = 1; i < m; i++)
    {
        a[i][i - 1] = 1;
    }
    a = binpow(a, n);

    cout << a[0][0] << endl;
    /*for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;   
    }*/
}

void write()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}