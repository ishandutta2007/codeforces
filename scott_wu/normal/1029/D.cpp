#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ll;
const int MAXN = 300100;

int N, K;
map <int, int> mm;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ll clo = 10;
    ll res = 0;
    for (int d = 0; d < 10; d++)
    {
        mm.clear();
        for (int i = 0; i < N; i++)
        {
            mm[(clo * arr[i]) % K]++;
        }
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < clo && arr[i] * 10LL >= clo)
            {
                int gmod = ((-arr[i]) % K + K) % K;
                res += mm[gmod];
                if ((arr[i] * (clo + 1)) % K == 0)
                    res--;
            }
        }
        clo *= 10;
    }
    cout << res << "\n";
}