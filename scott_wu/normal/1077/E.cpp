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

int N, D;
int arr[MAXN];
map <int, int> mc;

int figure (int M)
{
    int nlo = 1e9;
    for (int i = 0; i < M; i++)
        nlo = min (nlo, arr[i] / (1 << (M - 1 - i)));
    return nlo * ((1 << M) - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        mc[t]++;
    }

    D = 0;
    for (pair <int, int> pp : mc)
        arr[D++] = pp.second;

    sort (arr, arr + D);
    reverse (arr, arr + D);

    int ans = 0;
    for (int i = 1; i <= min (30, D); i++)
        ans = max (ans, figure (i));
    cout << ans << "\n";
}