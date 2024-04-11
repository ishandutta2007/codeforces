#include <iostream>
using namespace std;
typedef long long ll;

ll x[200005];
char c[200005];
int b[200005], r[200005], p[200005];

int main()
{
    int n;
    cin >> n;
    int cnt[3]{0};
    for(int i = 0; i < n; i++){
        cin >> x[i] >> c[i];
        if(c[i] == 'B'){
            b[cnt[0]] = i;
            cnt[0]++;
        }
        if(c[i] == 'R'){
            r[cnt[1]] = i;
            cnt[1]++;
        }
        if(c[i] == 'P'){
            p[cnt[2]] = i;
            cnt[2]++;
        }
    }
    if(cnt[2] == 0){
        cout << x[b[cnt[0] - 1]] - x[b[0]] + x[r[cnt[1] - 1]] - x[r[0]] << endl;
        return 0;
    }
    b[cnt[0]] = n;
    r[cnt[1]] = n;
    ll ans = 0;
    int i = 0, j = 0, k = 0;
    if(b[i] < p[k]){
        ans += x[p[k]] - x[b[i]];
        while(b[i] < p[k]) i++;
    }
    if(r[j] < p[k]){
        ans += x[p[k]] - x[r[j]];
        while(r[j] < p[k]) j++;
    }
    for(; k < cnt[2] - 1; k++){
        if(b[i] > p[k + 1] || r[j] > p[k + 1]){
            ans += x[p[k + 1]] - x[p[k]];
            if(b[i] < p[k + 1]){
                ll d = x[b[i]] - x[p[k]];
                i++;
                while(b[i] < p[k + 1]){
                    d = max(d, x[b[i]] - x[b[i - 1]]);
                    i++;
                }
                d = max(d, x[p[k + 1]] - x[b[i - 1]]);
                ans += x[p[k + 1]] - x[p[k]] - d;
            }
            if(r[j] < p[k + 1]){
                ll d = x[r[j]] - x[p[k]];
                j++;
                while(r[j] < p[k + 1]){
                    d = max(d, x[r[j]] - x[r[j - 1]]);
                    j++;
                }
                d = max(d, x[p[k + 1]] - x[r[j - 1]]);
                ans += x[p[k + 1]] - x[p[k]] - d;
            }
        }
        else{
            ll d1 = x[b[i]] - x[p[k]];
            i++;
            while(b[i] < p[k + 1]){
                d1 = max(d1, x[b[i]] - x[b[i - 1]]);
                i++;
            }
            d1 = max(d1, x[p[k + 1]] - x[b[i - 1]]);
            ll d2 = x[r[j]] - x[p[k]];
            j++;
            while(r[j] < p[k + 1]){
                d2 = max(d2, x[r[j]] - x[r[j - 1]]);
                j++;
            }
            d2 = max(d2, x[p[k + 1]] - x[r[j - 1]]);
            ans += x[p[k + 1]] - x[p[k]] + min(x[p[k + 1]] - x[p[k]], (x[p[k + 1]] - x[p[k]]) * 2 - d1 - d2);
        }
    }
    if(b[cnt[0] - 1] > p[cnt[2] - 1]) ans += x[b[cnt[0] - 1]] - x[p[cnt[2] - 1]];
    if(r[cnt[1] - 1] > p[cnt[2] - 1]) ans += x[r[cnt[1] - 1]] - x[p[cnt[2] - 1]];
    cout << ans << endl;
}