#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int n, k;
string s;
int a[MN];
vpii invs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;
    F0R(i, n){
        a[i] = (s[i]=='R');
    }
    
    int ninv = 0;
    int j = 0;
    bool cont = true;
    while(cont){
        ++j;
        cont = false;
        F0R(i, n-1){
            if(a[i] > a[i+1]){
                invs.pb({i, j});
                swap(a[i], a[i+1]);
                ++i;
                cont = true;
                ninv++;
            }
        }
    }
    //for(auto u : invs) cout << u.f << " " << u.s << "\n";
    //cout << "\n";
    --j;
    if(k < j || k > ninv){
        cout << "-1\n";
        return 0;
    }
    int cur = 0;
    FOR(i, 1, k){
        if(ninv-1-cur == k-i){
            cout << "1 " << invs[cur].f+1 << "\n";
            ++cur;
            continue;
        }

        vi now;
        while(invs[cur].s == i){
            now.pb(invs[cur].f);
            ++cur;
            if(ninv-cur == k-i) break;
        }
        cout << now.size() << " ";
        for(auto u : now) cout << u+1 << " ";
        cout << "\n";
    }
    
    return 0;
}