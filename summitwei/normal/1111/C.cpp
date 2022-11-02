#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, k;
ll a, b;
int locs[MN];

ll best(int l, int r){
    int amt = upper_bound(locs, locs+k, r)-lower_bound(locs, locs+k, l);
    if(amt == 0){
        return a;
    }
    if(l == r){
        return b*amt;
    }
    ll op1 = b*amt*(r-l+1);

    int mid = (l+r)/2;
    ll op2 = best(l, mid)+best(mid+1, r);

    return min(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> a >> b;
    F0R(i, k){
        cin >> locs[i];
    }
    sort(locs, locs+k);

    cout << best(1, 1<<n);
    
    return 0;
}