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

#define MN 1005
int n;
int l[MN], r[MN];
int val[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> l[i];
    FOR(i, 1, n) cin >> r[i];
    FOR(i, 1, n){
        val[i] = n-l[i]-r[i];
        if(val[i] <= 0){ cout << "NO\n"; return 0; }
    }
    FOR(i, 1, n){
        int cnt = 0;
        FOR(j, 1, i-1){
            if(val[j] > val[i]) ++cnt;
        }
        if(cnt != l[i]){ cout << "NO\n"; return 0; }
        cnt = 0;
        FOR(j, i+1, n){
            if(val[j] > val[i]) ++cnt;
        }
        if(cnt != r[i]){cout << "NO\n"; return 0;}
    }
    cout << "YES\n";
    FOR(i, 1, n) cout << val[i] << " ";
    cout << "\n";
    
    return 0;
}