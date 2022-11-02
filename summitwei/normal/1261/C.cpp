#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n, m;
vi gr[MN];
vi ps[MN];
vi vis[MN];
int tot;

bool chk(int x){
    vpii ok;
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(i<x || j<x || i+x>n+1 || j+x>m+1) continue;
            if(ps[i+x-1][j+x-1]-ps[i-x][j+x-1]-ps[i+x-1][j-x]+ps[i-x][j-x] == (2*x-1)*(2*x-1)){
                ok.pb({i, j});
            }
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            vis[i][j] = 0;
        }
    }
    int cnt = 0;
    queue<pii> q;
    for(auto u : ok){
        q.push(u);
        vis[u.f][u.s] = 1;
    }
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        ++cnt;
        if(vis[top.f][top.s] == x) continue;
        FOR(i, -1, 1){
            FOR(j, -1, 1){
                pii nn = {top.f+i, top.s+j};
                if(vis[nn.f][nn.s] == 0){
                    vis[nn.f][nn.s] = vis[top.f][top.s]+1;
                    q.push(nn);
                }
            }
        }
    }
    return cnt==tot;
}
void rec(int x){
    FOR(i, 1, n){
        FOR(j, 1, m){
            vis[i][j] = 0;
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(i<x || j<x || i+x>n+1 || j+x>m+1) continue;
            if(ps[i+x-1][j+x-1]-ps[i-x][j+x-1]-ps[i+x-1][j-x]+ps[i-x][j-x] == (2*x-1)*(2*x-1)){
                vis[i][j] = 1;
            }
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            cout << (vis[i][j]?'X':'.');
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    gr[0].resize(m+1);
    ps[0].resize(m+1);
    FOR(i, 1, n){
        gr[i].resize(m+1);
        ps[i].resize(m+1);
        vis[i].resize(m+1);
        FOR(j, 1, m){
            char c;
            cin >> c;
            gr[i][j] = c=='.'?0:1;
            ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+gr[i][j];
            if(gr[i][j] == 1) ++tot;
        }
    }
    int l=1, r=min(m,n)+2;
    while(l+1<r){
        //cout << "doing " << l << " " << r << "\n";
        int mid = (l+r)/2;
        if(chk(mid)){
            l=mid;
        } else{
            r=mid;
        }
    }
    cout << l-1 << "\n";
    rec(l);
    
    return 0;
}