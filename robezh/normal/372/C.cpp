#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int MAXN = 150500;

int n,m,d;
ll dp[2][MAXN], btot = 0;
int a[MAXN], b[MAXN], t[MAXN];

int main(){
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i < m; i++){scanf("%d%d%d", &a[i], &b[i], &t[i]); btot += b[i];}
    for(int i = 1; i <= n; i++){
        dp[0][i] = abs(a[0]-i);
    }
    for(int i = 1; i < m; i++){
        ll wid = 1LL * (t[i]-t[i-1]) * d;
        deque<P> dque;
        for(int j = 1; j <= min(wid, (ll)n); j++){
            while(!dque.empty() && dque.back().first >= dp[(i-1)&1][j]) dque.pop_back();
            dque.push_back({dp[(i-1)&1][j], j});
        }
        for(int j = 1; j <= n; j++){
            if(j+wid <= n){
                while(!dque.empty() && dque.back().first >= dp[(i-1)&1][j+wid]) dque.pop_back();
                dque.push_back({dp[(i-1)&1][j+wid], (int)(j+wid)});

            }
            while(dque.front().second < j-wid) dque.pop_front();
            dp[i&1][j] = dque.front().first + abs(a[i]-j);
        }
    }
    ll res = (ll)1e18;
    for(int i = 1; i <= n; i++) res = min(res, dp[(m-1)&1][i]);
    cout << btot - res;
}