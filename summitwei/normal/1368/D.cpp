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
 
#define MN 200005
#define MM 20
int n;
int a[MN];
int cnt[MM];
int b[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        F0R(j, 20){
            if(a[i] & (1<<j)){
                cnt[j]++;
            }
        }
    }
    F0R(j, 20){
        FOR(i, 1, cnt[j]){
            b[i] += (1<<j);
        }
    }
    ll sm = 0;
    FOR(i, 1, n){
        sm += 1LL*b[i]*b[i];
    }
    cout << sm << "\n";

    return 0;
}