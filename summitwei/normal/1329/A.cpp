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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
int m;
pii l[MN];
int ps[MN];
int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, m){
        cin >> l[i].f;
        l[i].s = i;
    }
    //sort(l, l+m);

    F0R(i, m){
        if(l[i].f > n-i){
            cout << "-1\n";
            return 0;
        }
    }

    RFOR(i, m-1, 0){
        ps[i] = min(ps[i+1]+l[i].f, MN);
    }
    if(ps[0] < n){
        cout << "-1\n";
        return 0;
    }
    int cur = 0;
    F0R(i, m){
        ans[l[i].s] = cur+1;
        cur = max(n-ps[i+1], cur+1);
    }
    F0R(i, m) cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}