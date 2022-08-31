#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 200100;

int Q;

int N;
ll price[MAXN];
int sc[MAXN];
int X, A;
int Y, B;
ll K;

bool works (int p)
{
    for (int i = 1; i <= p; i++)
    {
        sc[i-1] = 0;
        if (i % A == 0)
            sc[i-1] += X;
        if (i % B == 0)
            sc[i-1] += Y;
    }
    sort (sc, sc + p);
    reverse (sc, sc + p);

    ll ctot = 0;
    for (int i = 0; i < p; i++)
        ctot += price[i] * sc[i];
    return ctot >= K;
}

void roll()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
        price[i] /= 100;
    }
    cin >> X >> A >> Y >> B >> K;

    sort (price, price + N);
    reverse (price, price + N);

    if (!works (N))
    {
        cout << "-1\n";
        return;
    }

    int lo = 1, hi = N;
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

    cin >> Q;
    for (int q = 0; q < Q; q++)
        roll();
}