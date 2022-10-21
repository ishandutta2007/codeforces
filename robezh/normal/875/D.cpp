#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500, INF = (int)1e9 + 500;
typedef pair<int, int> P;

int n;
int num[N];
int l[N], r[N];
int gol[N][30], gor[N][30];
int bit[30];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    stack<P> S;

    S.push({INF, -1});
    for(int i = 0; i < n; i++){
        while(S.top().first <= num[i]) S.pop();
        l[i] = S.top().second + 1;
        S.push({num[i], i});
    }
    while(!S.empty()) S.pop();

    S.push({INF, n});
    for(int i = n - 1; i >= 0; i--){
        while(S.top().first < num[i]) S.pop();
        r[i] = S.top().second - 1;
        S.push({num[i], i});
    }

    {
        int x = num[0];
        for(int j = 0; j < 30; j++){
            bit[j] = x % 2; x /= 2;
            gol[0][j] = (bit[j] ? 0 : -1);
        }
    }
    for(int i = 1; i < n; i++){
        int x = num[i];
        for(int j = 0; j < 30; j++){
            bit[j] = x % 2; x /= 2;
            gol[i][j] = (bit[j] ? i : gol[i-1][j]);
        }
    }
    for(int i = 0; i < 30; i++) gor[n][i] = n;
    for(int i = n-1; i >= 0; i--){
        int x = num[i];
        for(int j = 0; j < 30; j++){
            bit[j] = x % 2; x /= 2;
            gor[i][j] = (bit[j] ? i : gor[i+1][j]);
        }
    }

    ll res = 1LL * n * (n - 1) / 2 + n;
    for(int i = 0; i < n; i++){
        int mx = r[i], mn = l[i];
        int x = num[i];
        for(int j = 0; j < 30; j++){
            if(x % 2 == 0){
                mx = min(mx, gor[i][j] - 1);
                mn = max(mn, gol[i][j] + 1);
            }
            x /= 2;
        }
//        cout << i << " " << mn << " " << mx << endl;
        res -= 1LL * (i - mn + 1) * (mx - i + 1);
    }
    cout << res << endl;
}