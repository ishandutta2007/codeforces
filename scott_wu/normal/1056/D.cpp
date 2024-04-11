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
const int MAXN = 100100;

int N;
int par[MAXN];
int ssize[MAXN];
int nhas[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        ssize[i] = 0;
        nhas[i] = 1;
    }
    for (int i = N - 1; i >= 1; i--)
    {
        ssize[i] += nhas[i];
        int p = par[i];
        ssize[p] += ssize[i];
        nhas[p] = 0;
    }
    if (N == 1) ssize[0] = 1;

    sort (ssize, ssize + N);
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << ssize[i];
    }
    cout << "\n";
}