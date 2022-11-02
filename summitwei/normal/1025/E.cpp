#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 55
int cnt;
int n, m;
pair<pii, int> a[MN];
pair<pii, int> b[MN];
vector<pair<pii, pii> > p1;
vector<pair<pii, pii> > p2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> a[i].f.f >> a[i].f.s;
        a[i].s = i;
    }
    FOR(i, 1, m){
        cin >> b[i].f.f >> b[i].f.s;
        b[i].s = i;
    }
    sort(a+1, a+1+m);
    sort(b+1, b+1+m);
    FOR(_, 1, m){
        FOR(i, 1, m){
            if(a[i].f.f == i) continue;
            int ok = true;
            FOR(j, 1, m){
                if(j == i) continue;
                if(a[i].f.f > i){
                    if(a[j].f.s == a[i].f.s && a[j].f.f >= i && a[j].f.f <= a[i].f.f){
                        ok = false;
                    }
                } else{
                    if(a[j].f.s == a[i].f.s && a[j].f.f <= i && a[j].f.f >= a[i].f.f){
                        ok = false;
                    }
                }
            }
            if(ok){
                p1.pb({a[i].f, {i, a[i].f.s}});
                cnt += abs(a[i].f.f-i);
                a[i].f = {i, a[i].f.s};
            }
        }
        FOR(i, 1, m){
            if(b[i].f.f == i) continue;
            int ok = true;
            FOR(j, 1, m){
                if(j == i) continue;
                if(b[i].f.f > i){
                    if(b[j].f.s == b[i].f.s && b[j].f.f >= i && b[j].f.f <= b[i].f.f){
                        ok = false;
                    }
                } else{
                    if(b[j].f.s == b[i].f.s && b[j].f.f <= i && b[j].f.f >= b[i].f.f){
                        ok = false;
                    }
                }
            }
            if(ok){
                p2.pb({b[i].f, {i, b[i].f.s}});
                cnt += abs(b[i].f.f-i);
                b[i].f = {i, b[i].f.s};
            }
        }
    }
    FOR(i, 1, m){
        p1.pb({a[i].f, {i, a[i].s}});
        p2.pb({b[i].f, {i, b[i].s}});
        cnt += abs(a[i].f.f-a[i].s)+abs(a[i].f.s-a[i].s);
    }
    FOR(i, 1, m){
        p1.pb({{i, a[i].s}, {a[i].s, a[i].s}});
        p2.pb({{i, b[i].s}, {b[i].s, b[i].s}});
        cnt += abs(b[i].f.f-b[i].s)+abs(b[i].f.s-b[i].s);
    }
    
    cout << cnt << "\n";
    F0R(i, p1.size()){
        if(p1[i].f.f == p1[i].s.f){
            FOR(j, p1[i].f.s, p1[i].s.s-1){
                cout << p1[i].f.f << " " << j << " " << p1[i].f.f << " " << j+1 << "\n";
            }
            RFOR(j, p1[i].f.s, p1[i].s.s+1){
                cout << p1[i].f.f << " " << j << " " << p1[i].f.f << " " << j-1 << "\n";
            }
        } else{
            FOR(j, p1[i].f.f, p1[i].s.f-1){
                cout << j << " " << p1[i].f.s << " " << j+1 << " " << p1[i].f.s << "\n";
            }
            RFOR(j, p1[i].f.f, p1[i].s.f+1){
                cout << j << " " << p1[i].f.s << " " << j-1 << " " << p1[i].f.s << "\n";
            }
        }
    }
    RFOR(i, p2.size()-1, 0){
        if(p2[i].f.f == p2[i].s.f){
            FOR(j, p2[i].s.s, p2[i].f.s-1){
                cout << p2[i].f.f << " " << j << " " << p2[i].f.f << " " << j+1 << "\n";
            }
            RFOR(j, p2[i].s.s, p2[i].f.s+1){
                cout << p2[i].f.f << " " << j << " " << p2[i].f.f << " " << j-1 << "\n";
            }
        } else{
            FOR(j, p2[i].s.f, p2[i].f.f-1){
                cout << j << " " << p2[i].f.s << " " << j+1 << " " << p2[i].f.s << "\n";
            }
            RFOR(j, p2[i].s.f, p2[i].f.f+1){
                cout << j << " " << p2[i].f.s << " " << j-1 << " " << p2[i].f.s << "\n";
            }
        }
    }

    return 0;
}