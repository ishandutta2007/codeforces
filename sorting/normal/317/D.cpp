

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 4e4;

ll n;
int grundy[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
int cnt[31];
bool vis[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ++cnt[1];
    ll i;
    for(i = 2; i * i <= n; ++i){
        if(vis[i]) continue;
        int i_cnt = 0;
        ll x = i;
        while(x <= n){
            if(x * x <= n) vis[x] = true;
            else --cnt[1];
            ++i_cnt;
            x *= i;
        }

        ++cnt[i_cnt];
    }

    --i;
    cnt[1] += n - i;

    int ans = 0;
    for(int i = 1; i < 30; ++i){
        if(cnt[i] % 2 == 0) continue;
        ans ^= grundy[i];
    }

    if(ans) cout << "Vasya\n";
    else cout << "Petya\n"; 
}