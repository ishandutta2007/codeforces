#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 300005
int n, k;
pii s[MN]; //(beau, len)

priority_queue<int, vi, greater<int> > pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(i, n){
        cin >> s[i].s >> s[i].f;
    }

    sort(s, s+n, greater<pii>());

    ll mx = 0;
    ll sm = 0;
    F0R(i, n){
        pq.push(s[i].s);
        sm += s[i].s;
        //if(pq.size() < k) continue;

        while(pq.size() > k){
            int top = pq.top();
            pq.pop();
            sm -= (ll)top;
        }

        ll ans = 1LL*s[i].f*sm;
        mx = max(mx, ans);
    }

    cout << mx << "\n";
    
    return 0;
}