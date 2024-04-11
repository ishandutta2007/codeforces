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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int a[MN];
int fst[MN];
int lst[MN];
int cnt;
struct Aah{
    int fst, lst, ind;
};
bool comp(Aah a, Aah b){
    if(a.fst != b.fst) return a.fst < b.fst;
    return a.ind < b.ind;
}
Aah oof[MN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    F0R(_, q){
        cin >> n;
        cnt = 0;
        FOR(i, 1, n){
            cin >> a[i];
            lst[a[i]] = i;
            if(fst[a[i]] == 0){
                fst[a[i]] = i;
            }
        }

        FOR(i, 1, n){
            if(fst[i] == 0) continue;
            oof[cnt].fst = fst[i];
            oof[cnt].lst = lst[i];
            oof[cnt].ind = i;
            ++cnt;
        }

        /*sort(oof, oof+cnt, comp);

        int mx = 0;
        F0R(i, cnt){
            int val = que(1, 1, n, 1, oof[i].fst-1);
            mx = max(mx, val+1);
            upd(1, 1, n, oof[i].lst, oof[i].lst, val+1);
        }*/
        int mx = 1;
        int cur = 1;
        FOR(i, 1, cnt-1){
            //cout << i << " cur " << cur << "\n";
            if(oof[i].fst > oof[i-1].lst){
                ++cur;
                mx = max(cur, mx);
            } else{
                cur = 1;
            }
        }

        cout << cnt-mx << "\n";

        FOR(i, 1, n){
            a[i] = 0;
            fst[i] = 0;
            lst[i] = 0;
            oof[i].fst = 0;
            oof[i].lst = 0;
            oof[i].ind = 0;
        }
    }
    
    return 0;
}