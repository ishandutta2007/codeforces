#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 5005
int n, m;
int s[MN];
pii a[MN];
bool okl[MN];
bool okr[MN];
int cntL[MN];
int cntR[MN];
bool nou[MN];
 
int mx;
ll fin;
int cur;
ll ans;
 
int wtmoo(int x, int y){
    if(x < y) swap(x, y);
    if(x == 1 && y == 1) return 1;
    if(x == 0 && y == 0) return 0;
    if(y == 0) return 1;
    return 2;
}
ll calc(int x, int y){
    if(x < y) swap(x, y);
    if(y == 0) return max(1, x);
    if(x == 1 && y == 1){
        return 2;
    }
    return max(1LL, (1LL*y*(x-1))%MOD);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> s[i];
    }
    F0R(i, m){
        cin >> a[i].f >> a[i].s;
    }
    F0R(i, m){
        int cnt = 0;
        int l = -1;
        FOR(j, 1, n){
            if(s[j] == a[i].f) ++cnt;
            if(cnt == a[i].s){
                okl[j] = true;
                l = j;
                break;
            }
        }
        cnt = 0;
        RFOR(j, n, 1){
            if(s[j] == a[i].f) ++cnt;
            if(cnt == a[i].s){
                okr[j] = true;
                if(l != -1){
                    if(l < j){
                        nou[l] = true;
                        //cout << i << " will see\n";
                    }
                }
                break;
            }
        }
    }
    RFOR(j, n, 1){
        if(okr[j]){
            ++cntR[s[j]];
        }
    }
    ans = 1;
    FOR(i, 1, n){
        if(cntR[i] != 0){
            ++cur;
            ans *= cntR[i];
            ans %= MOD;
        }
    }
    mx = cur;
    fin = ans;
 
    FOR(i, 1, n){
        if(okr[i]){
            --cntR[s[i]];
        }
        if(okl[i]){
            ++cntL[s[i]];
        }
 
        cur = 0; ans = 1;
        FOR(j, 1, n){
            //cout << cntL[j] << " " << cntR[j] << "\n";
            if(okl[i] && s[i] == j){
                int aah = cntR[j];
                if(nou[i]){
                    --aah;
                }
                if(aah == 0){
                    ++cur;
                } else{
                    cur += 2;
                    ans = (ans*aah)%MOD;
                }
            } else{
                cur += wtmoo(cntL[j], cntR[j]);
                ans = (ans*calc(cntL[j], cntR[j])) % MOD;
            }
        }
        if(okl[i]){
            if(cur > mx){
                mx = cur;
                fin = ans;
            } else if(cur == mx){
                fin = (fin+ans)%MOD;
            }
        }
        //cout << i << " " << cur << " " << ans << "\n";
    }
 
    cout << mx << " " << fin << "\n";
 
    return 0;
}