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
#define MOD 1000000000000000LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 200005
int n;
int a[MN];
map<int, vi> aah;
set<int> in;
int sm[2];
ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b);
            ex /= 2;
        } else{
            prod = (prod*b);
            ex--;
        }
    }
    
    return prod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        for(int j=2; j*j<=a[i]; ++j){
            int cnt = 0;
            while(a[i]%j == 0){
                //aah[i][j]++;
                a[i] /= j;
                in.insert(j);
                ++cnt;
            }
            aah[j].pb(cnt);
        }
        if(a[i] != 1){
            //aah[i][a[i]]++;
            aah[a[i]].pb(1);
            in.insert(a[i]);
        }
    }
    ll ans = 1;
    for(auto u : in){
        //cout << "doing " << u << "\n";
        sort(aah[u].begin(), aah[u].end());
        int res = 0;
        if(aah[u].size() == n) res = aah[u][1];
        else if(aah[u].size() == n-1) res = aah[u][0];
        ans = ans*modExp(u, res);
    }
    cout << ans << "\n";
    
    return 0;
}