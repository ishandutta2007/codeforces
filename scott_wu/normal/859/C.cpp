#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N;
int arr[MAXN];
int ps[MAXN];
int dp[MAXN]; // score starting at i if you are the decider

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    ps[N] = 0;
    for (int i = N - 1; i >= 0; i--)
        ps[i] = ps[i+1] + arr[i];

    dp[N] = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        dp[i] = max (dp[i+1], arr[i] + (ps[i+1] - dp[i+1])); // give or take
    }

    cout << ps[0] - dp[0] << " " << dp[0] << "\n";
}