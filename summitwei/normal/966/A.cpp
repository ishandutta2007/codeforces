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

#define MN 100005
int n, m, ns, ne, v;
int st[MN];
int el[MN];

int q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> ns >> ne >> v;
    F0R(i, ns){
        cin >> st[i];
    }
    F0R(i, ne){
        cin >> el[i];
    }

    sort(st, st+ns);
    sort(el, el+ne);

    cin >> q;
    F0R(_, q){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 > y2) swap(y1, y2);
        if(x1 == x2){
            cout << y2-y1 << "\n";
            continue;
        }

        int dist = INF;
        int locst = lower_bound(st, st+ns, y1)-st;
        if(locst != ns){
            int loc = st[locst];
            int cd = abs(y1-loc)+abs(y2-loc)+abs(x2-x1);
            dist = min(dist, cd);
        }
        if(locst != 0){
            locst--;
            int loc = st[locst];
            int cd = abs(y1-loc)+abs(y2-loc)+abs(x2-x1);
            dist = min(dist, cd);
        }

        int locel = lower_bound(el, el+ne, y1)-el;
        if(locel != ne){
            int loc = el[locel];
            int cd = abs(y1-loc)+abs(y2-loc)+(abs(x2-x1)+v-1)/v;
            dist = min(dist, cd);
        }
        if(locel != 0){
            locel--;
            int loc = el[locel];
            int cd = abs(y1-loc)+abs(y2-loc)+(abs(x2-x1)+v-1)/v;
            dist = min(dist, cd);
        }

        cout << dist << "\n";
    }

    return 0;
}