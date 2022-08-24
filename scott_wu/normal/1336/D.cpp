#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N;
int ttot, stot;
int cnt[MAXN];

pair <int, int> ask (int x)
{
    cout << "+ " << x + 1 << endl << flush;
    int tnew, snew;
    cin >> tnew >> snew;

    pair <int, int> res = make_pair (tnew - ttot, snew - stot);
    ttot = tnew;
    stot = snew;
    return res;
}

int gf (int x)
{
    // just added 1 and x new trips
    int res = 2;
    while ((res - 1) * (res - 2) / 2 < x)
        res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> ttot >> stot;

    pair <int, int> p1 = ask (0);
    pair <int, int> p2 = ask (1);
    pair <int, int> p3 = ask (2);
    pair <int, int> p4 = ask (0);

    cnt[0] = gf (p4.first);
    if (p2.second)
        cnt[2] = gf (p3.first);
    else
        cnt[2] = 1;
    cnt[1] = p4.second / cnt[2];

    int nnext = p3.second - (cnt[0] - 1) * cnt[1];
    for (int i = 3; i < N - 1; i++)
    {
        pair <int, int> np = ask (i);
        if (nnext == 0) cnt[i] = 1;
        else cnt[i] = gf (np.first);
        nnext = np.second - cnt[i-2] * cnt[i-1];
    }
    cnt[N-1] = nnext / cnt[N-3];

    cout << "!";
    for (int i = 0; i < N; i++)
    {
        cout << " ";

        if (i == 0) cout << cnt[i] - 2;
        else if (i == N - 1) cout << cnt[i];
        else cout << cnt[i] - 1;
    }
    cout << "\n";
}