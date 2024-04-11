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

#define MN 2005

struct Point{
    ll x, y;

    bool operator <(const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

int n;
Point coor[MN];
bool used[MN];

int ccw(int x, int y, int z){
    Point a = coor[x];
    Point b = coor[y];
    Point c = coor[z];
    ll dx1 = b.x-a.x;
    ll dy1 = b.y-a.y;
    ll dx2 = c.x-a.x;
    ll dy2 = c.y-a.y;

    if(dx1*dy2 > dy1*dx2) return 1;
    if(dx1*dy2 < dy1*dx2) return -1;

    if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
    if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return 1;

    return 0;
}

vi ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cur = 0;
    cin >> n;
    F0R(i, n){
        cin >> coor[i].x >> coor[i].y;
        if(coor[i].x < coor[cur].x) cur = i;
    }

    ans.pb(cur);
    used[cur] = true;
    F0R(_, n-2){
        char c;
        cin >> c;
        int ind = -1;
        if(c == 'L'){
            F0R(i, n){
                if(used[i]) continue;
                if(ind == -1){
                    ind = i;
                    continue;
                }
                if(ccw(cur, i, ind) == 1){
                    ind = i;
                }
            }
        } else{
            F0R(i, n){
                if(used[i]) continue;
                if(ind == -1){
                    ind = i;
                    continue;
                }
                if(ccw(cur, i, ind) == -1){
                    ind = i;
                }
            }
        }
        cur = ind;
        used[ind] = true;
        ans.pb(ind);
    }
    F0R(i, n){
        if(!used[i]){
            ans.pb(i);
            break;
        }
    }

    F0R(i, n){
        cout << ans[i]+1 << " ";
    }
    
    return 0;
}