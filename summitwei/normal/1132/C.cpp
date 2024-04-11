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

#define MN 5005
int n, q;
pii p[MN];

int reg[MN];
int onect[MN];
int twoct[MN];
int ovct[MN];

int gr(int i, int j){ //get ct of 2s in range
    int rb = min(p[i].s, p[j].s);
    int lb = max(p[i].f, p[j].f);
    
    if(lb > rb) return 0;
    return twoct[rb]-twoct[lb-1];
}

bool comp(pii a, pii b){
    if(a.f != b.f) return a.f<b.f;
    return a.s > b.s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    F0R(i, q){
        cin >> p[i].f >> p[i].s;
    }
    sort(p, p+q);
    
    
    F0R(i, q){
        FOR(j, p[i].f, p[i].s){
            reg[j]++;
        }
    }
    
    FOR(i, 1, n){
        if(reg[i] == 2){
            twoct[i] = twoct[i-1]+1;
        } else{
            twoct[i] = twoct[i-1];
        }
        if(reg[i] == 1){
            onect[i] = onect[i-1]+1;
        } else{
            onect[i] = onect[i-1];
        }
        
        if(reg[i] > 0){
            ovct[i] = ovct[i-1]+1;
        } else{
            ovct[i] = ovct[i-1];
        }
    }
    
    int mx = 0;
    F0R(i, q-1){
        FOR(j, i+1, q-1){
            int ict = onect[p[i].s]-onect[p[i].f-1];
            int jct = onect[p[j].s]-onect[p[j].f-1];
            int combct = gr(i, j);
            mx = max(mx, ovct[n]-ict-jct-combct);
        }
    }
    
    cout << mx << "\n";
    
    return 0;
}