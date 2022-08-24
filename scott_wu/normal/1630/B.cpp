#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, K;
int arr[MAXN];
int nv[MAXN];

void gogo()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i <= N; i++)
        nv[i] = 0;
    for (int i = 0; i < N; i++)
        nv[arr[i]]++;

    for (int i = 1; i <= N; i++)
        nv[i] += nv[i-1];

    int blo = 0, bhi = N;
    int cloc = 0;
    for (int i = 0; i < N; i++)
    {
        while (cloc < N && (nv[cloc] - nv[i]) * 2 - N < K)
            cloc++;
        if ((nv[cloc] - nv[i]) * 2 - N >= K && (cloc - i) < (bhi - blo))
        {
            blo = i;
            bhi = cloc;
        }
    }

    cout << blo + 1 << " " << bhi << "\n";

    int ctot = 0;
    int clast = 0;
    int knum = 1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > blo && arr[i] <= bhi) ctot++;
        else ctot--;
        if (ctot == knum && knum < K)
        {
            cout << clast + 1 << " " << i + 1 << "\n";
            clast = i + 1;
            knum++;
        }
    }
    cout << clast + 1 << " " << N << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}