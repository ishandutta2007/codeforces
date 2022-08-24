#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

bool compat(int x, int y)
{
    if (x == 0 || y == 0)
        return false;
    ll c = x * (ll) y;
    if (c < 0)
        return false;

    ll d = (ll) (sqrt (c) + 0.1);
    if (d * d == c)
        return true;
    return false;
}

int N;
int arr[MAXN];
int lval[MAXN];
int res[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        res[i] = 0;
    }
    res[N] = 0;

    for (int i = 0; i < N; i++)
    {
        lval[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (compat (arr[i], arr[j]))
                lval[i] = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int cscore = 0;
        for (int j = i; j < N; j++)
        {
            if (arr[j] != 0 && j >= i && lval[j] < i)
                cscore++;
            res[max (1, cscore)]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i > 1) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}