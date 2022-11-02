#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 100005
int n;
int p[MN];
vi ch[MN];
int d[MN];
int amt[MN];

void dfs(int cn){
    for(auto nn : ch[cn]){
        d[nn] = d[cn]+1;
        amt[d[nn]]++;
        dfs(nn);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 2, n){
        cin >> p[i];
        ch[p[i]].pb(i);
    }
    amt[0] = 1;
    dfs(1);

    int cnt = 0;
    F0R(i, n){
        if(amt[i] % 2 == 1){
            ++cnt;
        }
    }

    cout << cnt << "\n";
    return 0;
}