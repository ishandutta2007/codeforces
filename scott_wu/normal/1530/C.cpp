#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int A[MAXN], B[MAXN];

int av[MAXN], bv[MAXN];

bool works (int x)
{
    for (int i = 0; i < N; i++)
    {
        av[i] = A[i];
        bv[i] = B[i];
    }
    for (int i = 0; i < x; i++)
    {
        av[i+N] = 100;
        bv[i+N] = 0;
    }

    x += N;
    sort (av, av + x);
    reverse (av, av + x);
    sort (bv, bv + x);
    reverse (bv, bv + x);

    int nn = x - (x / 4);
    int res = 0;
    for (int i = 0; i < nn; i++)
        res += av[i] - bv[i];
    if (res >= 0) return true;
    return false;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int lo = 0, hi = N + 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}