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

int N, K;
int a[MAXN];
int b[MAXN];
int nbest[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++)
        nbest[i] = -1;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        nbest[a[i]] = max (nbest[a[i]], b[i]);
    }

    vector <int> v;
    for (int i = 0; i < N; i++)
    {
        if (nbest[a[i]] == b[i])
        {
            nbest[a[i]] = -2;
        }
        else
            v.push_back(b[i]);
    }
    sort(v.begin(), v.end());

    int nc = 0;
    for (int i = 0; i < K; i++)
        if (nbest[i] == -1)
            nc++;

    ll ans = 0;
    for (int i = 0; i < nc; i++)
        ans += v[i];
    cout << ans << "\n";
}