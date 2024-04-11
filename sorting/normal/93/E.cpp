#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e2 + 3;
const long long k_MAX = 1e5 + 3;

long long n, k;
int a[k_N];

long long dp[k_MAX][k_N];

long long solve(long long number, int position){
    if(position == k)
        return number;
    if(number < k_MAX && dp[number][position] != -1)
        return dp[number][position];

    long long answer = solve(number, position + 1) - solve(number / a[position], position + 1);
    if(number < k_MAX)
        dp[number][position] = answer;

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < k; ++i)
        cin >> a[i];

    sort(a, a + k);
    reverse(a, a + k);

    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0) << "\n";
}