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

#define MN 300005
int n, x1, x2;
pii c[MN];

bool swp = false;

int ou[MN];
int tu[MN];
//if this is the smallest term, how many do you need

vi fir;
vi sec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x1 >> x2;
    F0R(i, n){
        cin >> c[i].f;
        c[i].s = i;
    }

    if(x1 > x2){
        swap(x1, x2);
        swp = true;
    }

    sort(c, c+n, greater<pii>());

    F0R(i, n){
        ou[i] = (x1+c[i].f-1)/c[i].f;
        tu[i] = (x2+c[i].f-1)/c[i].f;

        //cout << ou[i] << " " << tu[i] << "\n";
    }

    bool works = false;

    F0R(i, n){
        //cout << i << " other index is " << i-ou[i] << "\n";
        if(i>=ou[i] && (i-ou[i]+1) >= tu[i-ou[i]]){
            works = true;
            FOR(j, 0, i-ou[i]){
                sec.pb(c[j].s);
            }
            FOR(j, i-ou[i]+1, i){
                fir.pb(c[j].s);
            }
            break;
        }
        if(i>=tu[i] && (i-tu[i]+1) >= ou[i-tu[i]]){
            works = true;
            FOR(j, 0, i-tu[i]){
                fir.pb(c[j].s);
            }
            FOR(j, i-tu[i]+1, i){
                sec.pb(c[j].s);
            }
            break;
        }
    }

    if(!works){
        cout << "No\n";
    } else{
        cout << "Yes\n";
        if(swp) swap(fir, sec);

        cout << fir.size() << " " << sec.size() << "\n";
        F0R(i, fir.size()) cout << fir[i]+1 << " ";
        cout << "\n";
        F0R(i, sec.size()) cout << sec[i]+1 << " ";
    }

    return 0;
}