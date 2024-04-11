#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
#define MR 455
#define RT 450
int n;
string s;
int a[MN];
int ps[MN];
int fs[MN];
int ls[MN];
int smh[MN*MR];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.length();
    memset(fs, 0x3f, sizeof fs);
    fs[0] = 0;
    ls[0] = 0;
    FOR(i, 1, n){
        a[i] = s[i-1]-'0';
        ps[i] = ps[i-1]+a[i];
        fs[ps[i]] = min(fs[ps[i]], i);
        ls[ps[i]] = max(ls[ps[i]], i);
    }
    ll ans = 0;
    FOR(j, 1, RT){
        int cv = -INF;
        int cc = 0;
        FOR(i, 0, n){
            int v = ps[i]*j+MN-i;
            ans += smh[v];
            ++smh[v];
        }
        FOR(i, 0, n){
            int v = ps[i]*j+MN-i;
            --smh[v];
        }
    }
    //cout << ans << "\n";
    FOR(d, 1, RT+5){
        FOR(i, 0, n){
            int v = ps[i];
            int j = d+v;
            if(j > ps[n]) break;
            int l = fs[j], r = ls[j];
            int dl = l-i, dr = r-i;
            int al = (dl+d-1)/d, ar = dr/d;
            //cout << l << " " << r << " " << dl << " " << dr << " " << al << " " << ar << "\n";
            al = max(al, RT+1);
            int amt = ar-al+1;
            ans += max(amt, 0);
        }
    }
    cout << ans << "\n";

    return 0;
}