#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

bool f[40000];

int main(){
    int k;
    cin >> k;
    int n[20];
    ll a[20][5002];
    ll s[20] {0};
    map<ll, int> mp;
    for(int i = 0; i < k; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            cin >> a[i][j];
            s[i] += a[i][j];
            mp[a[i][j]] = i + 1;
        }
    }
    ll m = 0;
    for(int i = 0; i < k; i++) m += s[i];
    if(m % k){
        cout << "No" << endl;
        return 0;
    }
    m /= k;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n[i]; j++){
            bool g = true;
            ll first = a[i][j];
            int bit = (1 << i);
            ll now = m - s[i] + a[i][j];
            while(now != first){
                int d = mp[now];
                if(d == 0){
                    g = false;
                    break;
                }
                d--;
                if(bit & (1 << d)){
                    g = false;
                    break;
                }
                bit |= (1 << d);
                now = m - s[d] + now;
            }
            if(g){
                f[bit] = true;
            }
        }
    }
    f[0] = true;
    int pre[40000];
    for(int i = 0; i < (1 << k); i++) pre[i] = -1;
    for(int i = 0; i < (1 << k); i++){
        for(int j = i; ; j = ((j - 1) & i)){
            if(f[j] && f[i & (~j)]){
                f[i] = true;
                pre[i] = j;
                break;
            }
            if(j == 0) break;
        }
    }
    if(!f[(1 << k) - 1]){
        cout << "No" << endl;
        return 0;
    }
    else{
        cout << "Yes" << endl;
        queue<int> que;
        que.push((1 << k) - 1);
        vector<int> c;
        while(que.size()){
            int now = que.front();
            que.pop();
            if(pre[now] != now){
                que.push(pre[now]);
                que.push(now & (~pre[now]));
            }
            else c.push_back(now);
        }
        ll ansc[20], ansp[20];
        fill(f, f + (1 << k), false);
        for(int x : c) f[x] = true;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n[i]; j++){
                bool g = true;
                ll first = a[i][j];
                int bit = (1 << i);
                ll now = m - s[i] + a[i][j];
                while(now != first){
                    int d = mp[now];
                    if(d == 0){
                        g = false;
                        break;
                    }
                    d--;
                    if(bit & (1 << d)){
                        g = false;
                        break;
                    }
                    bit |= (1 << d);
                    now = m - s[d] + now;
                }
                if(g){
                    if(f[bit]){
                        int d = i;
                        f[bit] = false;
                        now = m - s[i] + a[i][j];
                        while(now != first){
                            ansc[mp[now] - 1] = now;
                            ansp[mp[now] - 1] = d + 1;
                            d = mp[now] - 1;
                            now = m - s[d] + now;
                        }
                        ansc[mp[now] - 1] = now;
                        ansp[mp[now] - 1] = d + 1;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++) cout << ansc[i] << " " << ansp[i] << endl;
    }
}