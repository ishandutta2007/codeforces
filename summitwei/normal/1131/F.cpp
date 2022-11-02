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

#define MN 150005
int n;

vi grp[MN];
int dsu[MN];

int fd(int x){
    if(x == dsu[x]) return x;
    dsu[x] = fd(dsu[x]);
    return dsu[x];
}
void join(int a, int b){
    a = fd(a); b = fd(b);
    if(grp[a].size() < grp[b].size()) swap(a, b);

    dsu[b] = a;
    for(auto u : grp[b]){
        grp[a].pb(u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        dsu[i] = i;
        grp[i].pb(i);
    }
    F0R(i, n-1){
        int x, y;
        cin >> x >> y;
        join(x, y);
    }

    int lst = fd(1);
    F0R(i, grp[lst].size()){
        cout << grp[lst][i] << " ";
    }

    return 0;
}