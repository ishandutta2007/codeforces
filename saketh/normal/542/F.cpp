#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1028;

int N, T;

bool seen[MAXN][MAXN];
ll dp[MAXN][MAXN];
vector<int> qua[MAXN];

ll solve(int l, int f){
    f = min(f, 1000);
    if(l >= MAXN) return 0;
    if(seen[l][f]) return dp[l][f];
    seen[l][f] = true;

    ll sum = 0;
    for(int i=0; i<=qua[l].size(); i++){
        dp[l][f] = max(dp[l][f], sum + solve(l+1, 2*(f-i)));
        if(i>=f) break;
        if(i == qua[l].size()) break;
        sum += qua[l][i];
    }

    return dp[l][f];
}

int main(){
    cin >> N >> T;
    for(int i=0; i<N; i++){
        int tim, good;
        cin >> tim >> good;
        qua[T-tim].push_back(good);
    }

    for(int i=0; i<MAXN; i++)
        sort(qua[i].begin(), qua[i].end(), std::greater<int>());

    cout << solve(0, 1) << endl;
}