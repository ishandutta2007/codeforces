#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n, d;
int a[MN];
pii co[MN];

int dis(int x, int y){
    int cd = abs(co[x].f-co[y].f)+abs(co[x].s-co[y].s);
    return cd*d;
}

int ti[MN];
bool chk(int x){
    memset(ti, -1, sizeof ti);
    priority_queue<pii> aah;
    aah.push({x, 1});
    while(!aah.empty()){
        pii top = aah.top();
        aah.pop();
        int cn = top.s;
        if(ti[cn] != -1) continue;
        ti[cn] = top.f;
        FOR(i, 1, n){
            int nt = top.f-dis(cn, i);
            if(nt >= 0){
                aah.push({nt+a[i], i});
            }
        }
    }
    return ti[n] != -1;
}

int main(){
    cin >> n >> d;
    FOR(i, 2, n-1) cin >> a[i];
    FOR(i, 1, n){
        cin >> co[i].f >> co[i].s;
    }
    int l=0, r=INF; //more?
    while(l+1<r){
        int mid = (l+r)/2;
        if(chk(mid)){
            r = mid;
        } else{
            l = mid;
        }
    }
    cout << r << "\n";
    
    return 0;
}