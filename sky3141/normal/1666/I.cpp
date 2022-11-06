#include <iostream>

using namespace std;

int dig(int r, int c)
{
    int res;
    cout << "DIG " << r << ' ' << c << endl;
    cin >> res;
    return res;
}

int scan(int r, int c)
{
    int res;
    cout << "SCAN " << r << ' ' << c << endl;
    cin >> res;
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int d1 = scan(1, 1), d2 = scan(1, m);
    int sumx = (d1 - d2 + 2) / 2 + m;
    int sumy = d1 - sumx + 4;
    int d3 = scan(1, sumx / 2), d4 = scan(sumy / 2, 1);
    int difx = d3 - sumy + 2, dify = d4 - sumx + 2;
    int x1 = (sumx - difx) / 2, x2 = sumx - x1, y1 = (sumy - dify) / 2, y2 = sumy - y1;
    if (dig(y1, x1))
    {
        dig(y2, x2);
    }
    else
    {
        dig(y1, x2);
        dig(y2, x1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}