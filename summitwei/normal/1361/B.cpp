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

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int t;
int n, p;
map<int, int> k;
map<int, int> val;
int nz;
ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        k.clear();
        val.clear();
        cin >> n >> p;
        nz = -1;
        FOR(i, 1, n){
            int x;
            cin >> x;
            k[x]++;
        }
        if(p == 1){
            if(n%2) cout << "1\n";
            else cout << "0\n";
            continue;
        }
        //cout << "hmm\n";
        ll ans = 0;
        for(auto it = k.rbegin(); it!=k.rend(); ++it){
            //cout << "doing " << it->f << " " << it->s << "\n";
            int cnt = it->s;
            while(cnt != 0 && nz != -1){
                //cout << "proc del\n";
                int loc = it->f;
                --cnt;
                ans = (ans-modExp(p, loc)+MOD)%MOD;
                val[loc]--;
                while(val[loc] == -p){
                    val[loc] = 0;
                    ++loc;
                    val[loc]--;
                    if(val[loc] == 0){
                        nz = -1;
                    }
                }
            }
            if(cnt%2 == 1){
                //this gets a guy added
                int loc = it->f;
                val[loc]++;
                nz = loc;
                ans = (ans+modExp(p, loc))%MOD;
                //cout << "added\n";
            }
        }
        cout << ans << "\n";
    }

    return 0;
}