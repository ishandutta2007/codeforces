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
#define INF 100000000000000LL
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n, w;
ll sms[MN];
ll ans[MN];
vector<pll> tab[MN];

void upd(int l, int r, int v){
    sms[l] += v;
    sms[r+1] -= v;
}
void rec(){
    ans[0] = sms[0];
    FOR(i, 1, w){
        ans[i] = ans[i-1]+sms[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w;
    F0R(i, n){
        int l;
        cin >> l;
        tab[i].resize(l+1);
        F0R(j, l){
            cin >> tab[i][j].f;
            tab[i][j].s = j+1;
        }
        tab[i][l] = {0, -1}; //MAKE USE OF THIS, somehow
        sort(tab[i].begin(), tab[i].end(), greater<pll>() );
        set<int> hmm;
        F0R(j, l+1){
            int loc = tab[i][j].s;
            ll val = tab[i][j].f;
            if(loc == -1){
                hmm.insert(0);
                hmm.insert(l+1);
                //cout << "aah\n";
                continue;
            }
            set<int>::iterator ab = hmm.lower_bound(loc);
            int top;
            if(ab == hmm.end()) top = w;
            else top = *ab-1;
            int bot;
            if(ab == hmm.begin()) bot = 1;
            else bot = w-l+*(--ab)+1;
            
            if(top < bot) continue;

            //if positive (nonneg), set everything that can be touched (and is new)
            //if negative, set everything that must be touched (and is new)
            int rt = min(top, w-l+loc);
            int lt = max(bot, loc);
            //cout << lt << " " << rt << " " << val << "\n";
            upd(lt, rt, val);
            hmm.insert(loc);
        }
    }
    rec();

    FOR(i, 1, w){
        cout << ans[i] << " ";
    }

    return 0;
}