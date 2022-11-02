#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000009
#define EPSILON 0.00001
#define MAX_N 1005
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
pair<pll, pll> coords[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt = 0;

    cin >> N;
    F0R(i, N){
        //cout << "doing " << i << "\n";
        cin >> coords[i].f.f >> coords[i].f.s >> coords[i].s.f >> coords[i].s.s;
        ll minx = min(coords[i].f.f, coords[i].s.f);
        ll maxx = max(coords[i].f.f, coords[i].s.f);
        ll miny = min(coords[i].f.s, coords[i].s.s);
        ll maxy = max(coords[i].f.s, coords[i].s.s);

        ll currAmt = __gcd(abs(coords[i].f.f - coords[i].s.f), abs(coords[i].f.s - coords[i].s.s)) + 1;

        ll a, b, c, d, e, f;
        a = coords[i].s.s-coords[i].f.s;
        b = coords[i].f.f-coords[i].s.f;
        c = coords[i].f.s*coords[i].s.f - coords[i].f.f*coords[i].s.s;

        set<pll> ints;
        F0R(j, i){
            ll minx2 = min(coords[j].f.f, coords[j].s.f);
            ll maxx2 = max(coords[j].f.f, coords[j].s.f);
            ll miny2 = min(coords[j].f.s, coords[j].s.s);
            ll maxy2 = max(coords[j].f.s, coords[j].s.s);

            //cout << "doing " << i << " " << j << "\n";
            d = coords[j].s.s-coords[j].f.s;
            e = coords[j].f.f-coords[j].s.f;
            f = coords[j].f.s*coords[j].s.f - coords[j].f.f*coords[j].s.s;

            //cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "\n";

            ll yNum = a*f-c*d;
            ll yDenom = b*d-a*e;
            if(yDenom == 0 || yNum % yDenom != 0) continue;

            ll y = yNum/yDenom;
            //cout << "y is " << y << "\n";
            bool works = true;
            ll x;
            if(a != 0){
                if((b*y+c) % a == 0){
                    x = -(b*y+c)/a;
                } else{
                    works = false;
                }
            } else{
                if((e*y+f) % d == 0){
                    x = -(e*y+f)/d;
                } else{
                    works = false;
                }
            }
            /*if(works){
                cout << "x is " << x << "\n";
            }*/
            if(works && max(minx, minx2) <= x && x <= min(maxx, maxx2) && max(miny, miny2) <= y && y <= min(maxy, maxy2)){
                ints.insert(mp(x, y));
            }
        }

        //cout << currAmt << " " << ints.size() << "\n";
        cnt = cnt+currAmt-ints.size();
    }

    cout << cnt << "\n";

    return 0;
}