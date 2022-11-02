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

#define MN 200005
int n, t;
pair<pii, int> pr[MN];
bool chk(int x){
    int sm = 0;
    int cnt = 0;
    F0R(i, n){
        if(cnt == x) break;
        if(pr[i].f.s >= x){
            ++cnt;
            sm += pr[i].f.f;
        }
    }
    return cnt==x && sm<=t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    F0R(i, n){ cin >> pr[i].f.s >> pr[i].f.f; pr[i].s = i; }
    sort(pr, pr+n);
    int l=0, r=n+1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(chk(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    cout << l << "\n" << l << "\n";
    int cnt = 0;
    F0R(i, n){
        if(cnt == l) break;
        if(pr[i].f.s >= l){
            ++cnt;
            cout << pr[i].s+1 << " ";
        }
    }
    
    return 0;
}