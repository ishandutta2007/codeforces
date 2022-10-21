#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll powe(ll i, ll x){
    ll res = 1;
    while(x--) res *= i;
    return res;
}

ll a,b;
int cnt[10];
int n = 0;

ll dfs(int t, int e){
    if(t == 0) return 0;

    if(e == 0){
        for(int i = 9; i >= 0; i--){
            if(cnt[i] > 0){
                cnt[i] --;
                ll res=  dfs(t-1,0) + i * powe(10,t-1);
                return res;
            }
        }
    }

    ll dig = (b % powe(10,t)) / powe(10, t-1);
    if(cnt[dig] > 0){
        cnt[dig] --;
        ll res = dfs(t-1, 1);
        if(res != -1)
            return res + dig * powe(10,t-1);
        cnt[dig] ++;
    }
    for(int i = dig-1; i >= 0; i--){
        if(cnt[i] > 0){
            cnt[i]--;
            return dfs(t-1, 0) + i * powe(10,t-1);
        }
    }
    return -1;
}



int main() {
    fill(cnt, cnt+10, 0);
    cin >> a >> b;
    ll tmp = a;
    while(tmp > 0){
        n++;
        cnt[tmp%10] ++;
        tmp /= 10;
    }
    tmp = b;
    int k = 0;
    while(tmp > 0){
        tmp /= 10;
        k ++;
    }
    if(k > n) cout << dfs(n, 0);
    else cout << dfs(n, 1);
}