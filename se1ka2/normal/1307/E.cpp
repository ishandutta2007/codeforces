#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    int s[5002];
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i]--;
    }
    int l[5002], r[5002];
    vector<int> vl[5002], vr[5002];
    bool b[5002]{0};
    for(int i = 0; i < m; i++){
        int f, h;
        cin >> f >> h;
        f--;
        int c = 0;
        for(l[i] = 1; l[i] <= n; l[i]++){
            if(s[l[i]] == f) c++;
            if(c == h) break;
        }
        c = 0;
        for(r[i] = n; r[i] > 0; r[i]--){
            if(s[r[i]] == f) c++;
            if(c == h) break;
        }
        vl[f].push_back(l[i]);
        vr[f].push_back(r[i]);
        b[l[i]] = true;
    }
    b[0] = true;
    for(int i = 0; i < n; i++){
        sort(vl[i].begin(), vl[i].end());
        sort(vr[i].begin(), vr[i].end(), greater<int>());
    }
    ll ans = 0, num = 0;
    for(int i = 0; i <= n; i++){
        if(!b[i]) continue;
        ll c = 0, s = 1;
        for(int j = 0; j < n; j++){
            int p = 0, q = 0;
            bool f = false;
            for(int x : vr[j]){
                if(x > i) q++;
            }
            for(int x : vl[j]){
                if(x <= i) p++;
                if(x == i) f = true;
            }
            if(!f){
                if(p == 0){
                    s = s * max(q, 1) % MOD;;
                    c += min(1, max(q, 0));
                }
                else if(q == 0){
                    s = s * p % MOD;
                    c += 1;
                }
                else if(p == 1 && q == 1){
                    s = s * 2 % MOD;
                    c += 1;
                }
                else{
                    s = s * (p * q - min(p, q)) % MOD;
                    c += 2;
                }
            }
            else{
                if(q == 0){
                    c += 1;
                }
                else if(p == 1 && q == 1){
                    c += 1;
                }
                else if(p > q){
                    s = s * q % MOD;
                    c += 2;
                }
                else{
                    s = s * (q - 1) % MOD;
                    c += 2;
                }
            }
        }
        if(c > ans){
            ans = c;
            num = s;
        }
        else if(c == ans){
            num = (num + s) % MOD;
        }
    }
    cout << ans << " " << num << endl;
}