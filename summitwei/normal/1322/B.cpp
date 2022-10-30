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
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 400005
int n;
int a[MN];
 
int par;
bool comp(int x, int y){
    //cout << "chk " << x << " " << y << " " << par << "\n";
    if(x%par == y%par) return false;
    return x%par < y%par;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int oct = 0;
 
    cin >> n;
    F0R(i, n){
        cin >> a[i];
        if(a[i] % 2 == 1) ++oct;
    }
 
    int ans = 0;
 
    ll o = 1LL*oct*(n-oct);
    if(o % 2 == 1) ans = 1;
 
    FOR(i, 1, 25){
        par = 1<<(i+1);
        sort(a, a+n, comp);
 
        ll cnt = 0;
        int split = lower_bound(a, a+n, 1<<i, comp)-a;
        //cout << i << " " << split << "\n";
        int l=0, r=split-1;
        while(l<r){
            while(l < r && comp(a[l]+a[r], 1<<i)){
                //cout << l << " " << r << " " << i << " not good\n";
                ++l;
            }
            cnt += (r-l);
            --r;
        }
        //cout << i << " " << cnt << "\n";
        l=split; r=n-1;
        while(l<r){
            while(l<r && comp(a[l]+a[r], 1<<i)){
                ++l;
            }
            cnt += (r-l);
            --r;
        }
        //cout << i << " " << cnt << "\n";
        for(l=0, r=n; l<split; ++l){
            while(r >= split && comp(a[l]+a[r], 1<<i)){
                --r;
            }
            cnt += (r-split+1);
        }
 
        //cout << i << " " << cnt << "\n";
 
        if(cnt % 2 == 1){
            ans += (1<<i);
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}