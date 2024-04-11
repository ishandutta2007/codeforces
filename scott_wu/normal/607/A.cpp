#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
pair <int, int> cval[MAXN];
int dp[MAXN];

int find (int cloc)
{
    if (cloc <= cval[0].first) return 0;
    
    int lo = 0, hi = N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (cloc > cval[mid].first)
            lo = mid;
        else
            hi = mid - 1;
    }
    
    return lo + 1;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cval[i].first >> cval[i].second;
    
    sort (cval, cval + N);
    
    dp[0] = 0; //  # activated
    
    for (int i = 0; i < N; i++)
        dp[i+1] = dp[find (cval[i].first - cval[i].second)] + 1;
    
    int res = 0;
    for (int i = 0; i <= N; i++)
        res = max (res, dp[i]);
    cout << N - res << "\n";
    
    //system ("Pause");
    return 0;
}