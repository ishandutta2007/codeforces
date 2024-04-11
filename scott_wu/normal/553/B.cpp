#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N;
ll K;

ll fib[MAXN];
int res[MAXN];

void solve (int cloc)
{
    if (cloc >= N - 1) return;
    
    if (fib[cloc+1] <= K)
    {
        K -= fib[cloc+1];
        swap (res[cloc], res[cloc+1]);
        solve(cloc + 2);
    }
    solve(cloc + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    K--;
    fib[N] = fib[N-1] = 1;
    for (int i = N - 2; i >= 0; i--)
        fib[i] = fib[i+1] + fib[i+2];
    //cout << fib[0] << "\n";
    
    for (int i = 0; i < N; i++)
        res[i] = i + 1;
    
    solve (0);
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}