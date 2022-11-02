#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n, k;

ll modExp(ll a, ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return ans;
}
int a[8];
bool chk(){
    //F0R(i, k) cout << a[i] << " ";
    //cout << "\n";
    F0R(i, k){
        int cur = i;
        F0R(j, k){
            cur = a[cur];
            if(cur == 0) break;
        }
        if(cur != 0) return false;
    }
    //cout << "is ok\n";
    return true;
}
int cnt(int cur){
    if(cur == k){
        return chk();
    }
    int ans = 0;
    F0R(i, k){
        if(cur != 0 && i == cur) continue;
        a[cur] = i;
        ans += cnt(cur+1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    ll ans = modExp(n-k, n-k);
    ll res = cnt(0);
    cout << (ans*res)%MOD;

    return 0;
}