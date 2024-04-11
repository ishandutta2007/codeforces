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
#define INF 0x3f3f3f3f
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
int n, q;
deque<int> ree;
pii res[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    F0R(i, n){
        int x;
        cin >> x;
        ree.push_back(x);
    }

    FOR(i, 1, 300000){
        int t1 = ree.front();
        ree.pop_front();
        int t2 = ree.front();
        ree.pop_front();
        res[i] = mp(t1, t2);

        if(t1 > t2) swap(t1, t2);
        
        ree.push_front(t2);
        ree.push_back(t1);
    }

    F0R(_, q){
        ll c;
        cin >> c;
        //cout << res[c].f << " " << res[c].s << "\n";
        if(c <= 300000){
            cout << res[c].f << " " << res[c].s << "\n";
        } else{
            c %= (n-1);
            c += (2*(n-1));
            cout << res[c].f << " " << res[c].s << "\n";
        }
    }
    
    return 0;
}