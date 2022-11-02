#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205
int t;
int a, b, q;
bool ok[MN*MN];
int cnt[MN*MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        memset(ok, false, sizeof ok);
        memset(cnt, 0, sizeof cnt);
        cin >> a >> b >> q;
        F0R(i, a*b){
            if((i%a)%b != (i%b)%a) ok[i] = true;
            if(i == 0) cnt[i] = ok[i];
            else cnt[i] = cnt[i-1]+ok[i];
        }
        int ful = cnt[a*b-1];
        F0R(_, q){
            ll l, r;
            cin >> l >> r; --l;
            ll rans = 1LL*(r/(a*b)-1)*ful + cnt[r%(a*b)];
            ll lans = 1LL*(l/(a*b)-1)*ful + cnt[l%(a*b)];
            cout << rans-lans << " ";
        }
        cout << "\n";
    }
    
    return 0;
}