#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e6 + 5;
const int INF = 1e9;
int fst[MAXN], lst[MAXN], ri[MAXN], le[MAXN];
bool pfxgood[MAXN], sfxgood[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    fill(fst, fst + MAXN, INF);
    for(int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        lst[y] = i;
        if(fst[y] == INF)
            fst[y] = i;
    }
    pfxgood[0] = pfxgood[1] = true;
    sfxgood[x] = sfxgood[x + 1] = true;
    ri[0] = 0;
    le[x + 1] = INF;
    for(int i = 1; i <= x; i++)
        ri[i] = max(ri[i - 1], lst[i]);
    for(int i = x; i >= 1; i--)
        le[i] = min(le[i + 1], fst[i]);
    for(int i = 2; i <= x; i++) {
        if(fst[i] > ri[i - 1])
            pfxgood[i] = true;
        else
            break;
    }
    for(int i = x - 1; i >= 1; i--) {
        if(lst[i] < le[i + 1])
            sfxgood[i] = true;
        else
            break;
    }
    ll ans = 0;
    for(int l = 1; l <= x; l++) {
        if(!pfxgood[l - 1])
            break;
        int lo = l, hi = x;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(sfxgood[mi + 1] && le[mi + 1] > ri[l - 1])
                hi = mi;
            else
                lo = mi + 1;
        }
        ll tot = x - hi + 1;
        ans += tot;
    }
    cout << ans << endl;
}