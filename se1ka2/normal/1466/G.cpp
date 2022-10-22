#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

vector<int> Zalgorithm(string &s){
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
    int i = 1, j = 0;
    while(i < n){
        while(i + j < n && s[i + j] == s[j]) j++;
        a[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(i + k < n && k + a[k] < j){
            a[i + k] = a[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return a;
}

ll p[100005];
ll y[30][100005];

ll dfs(string &x, string &t, int d, int l, int k){
    if(d > k) return 0;
    if(l >= (int)x.size()){
        if(d < 20) return p[k - d];
        else return 0;
    }
    if(d >= 20) return y[x[l] - 'a'][k];
    ll res = 0;
    bool f = true;
    for(int i = l; i < (int)x.size(); i += (1 << (d + 1))){
        if(x[i] != t[d]){
            f = false;
            break;
        }
    }
    if(f) res = (res + dfs(x, t, d + 1, l + (1 << d), k)) % MOD;
    f = true;
    for(int i = l + (1 << d); i < (int)x.size(); i += (1 << (d + 1))){
        if(x[i] != t[d]){
            f = false;
            break;
        }
    }
    if(f) res = (res + dfs(x, t, d + 1, l, k)) % MOD;
    return res;
}

int main()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    int m = s.size();
    p[0] = 1;
    for(int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;
    for(int i = 20; i <= n; i++){
        for(int j = 0; j < 26; j++) y[j][i] = y[j][i - 1] * 2 % MOD;
        y[t[i - 1] - 'a'][i] = (y[t[i - 1] - 'a'][i] + 1) % MOD;
    }
    while(q--){
        int k;
        string w, u;
        cin >> k >> w;
        int l = w.size();
        ll ans = 0;
        if(l > m){
            u = w + s;
            w = s + w;
            reverse(u.begin(), u.end());
            vector<int> a = Zalgorithm(w);
            vector<int> b = Zalgorithm(u);
            for(int i = 0; i <= m; i++){
                bool f = true;
                for(int j = i; j < l; j += m + 1){
                    if(a[j + m] < min(m, l - j)){
                        f = false;
                        break;
                    }
                }
                if(i > 1){
                    f &= (b[m + l - (i - 1)] >= i - 1);
                }
                if(f){
                    string x;
                    for(int j = i - 1; j < l; j += m + 1){
                        if(j >= 0) x += w[j + m];
                    }
                    ans = (ans + dfs(x, t, 0, 0, k)) % MOD;
                }
            }
        }
        else{
            u = s + w;
            w = w + s;
            reverse(u.begin(), u.end());
            vector<int> a = Zalgorithm(w);
            vector<int> b = Zalgorithm(u);
            for(int i = 0; i <= m; i++){
                if(i < m && a[i + l] < min(l, m - i)) continue;
                if(i + l <= m) ans = (ans + p[k]) % MOD;
                else if(l + i > m + 1 && b[l + m - ((l + i) - (m + 1))] < (l + i) - (m + 1)) continue;
                else{
                    string x;
                    x += w[m - i];
                    ans = (ans + dfs(x, t, 0, 0, k)) % MOD;
                }
            }
        }
        cout << ans << endl;
    }
}