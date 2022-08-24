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

int N, M, K;
int arr[MAXN];

bool works (int s)
{
    int cm = 0, ccnt = K;
    for (int i = s; i < N; i++)
    {
        if (arr[i] <= ccnt)
        {
            ccnt -= arr[i];
        }
        else
        {
            ccnt = K - arr[i];
            cm++;
        }
    }
    if (ccnt < K) cm++;
    return cm <= M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int lo = 0, hi = N;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << N - lo << "\n";
}