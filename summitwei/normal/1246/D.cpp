#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
int p[MN];
vi ch[MN];
int d[MN];
int md[MN];

void gd(int cn){
    md[cn] = d[cn];
    for(auto &nn : ch[cn]){
        d[nn] = d[cn]+1;
        gd(nn);
        md[cn] = max(md[cn], md[nn]);
        if(md[nn] > md[ch[cn][0]]){
            swap(nn, ch[cn][0]);
        }
    }
}

vi od;
vi op;

void res(int cn){
    //cout << "res " << cn << "\n";
    od.pb(cn);
    for(auto u : ch[cn]){
        md[u] = md[cn];
    }
    FOR(i, 1, ch[cn].size()-1){
        int fn = ch[cn][i-1], nn = ch[cn][i];
        op.pb(fn);
        ++md[fn];
        md[nn] = md[fn];
        //cout << "merged " << fn << " " << nn << "\n";
        ch[nn].pb(fn);
        if(md[fn] > md[ch[nn][0]]){
            swap(ch[nn][0], ch[nn][ch[nn].size()-1]);
        }
    }
    if(ch[cn].size() != 0){
        res(ch[cn][ch[cn].size()-1]);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    cin >> n;
    FOR(i, 1, n-1){
        cin >> p[i];
        ch[p[i]].pb(i);
    }

    gd(0);
    res(0);
    
    for(auto u : od){
        cout << u << " ";
    }
    cout << "\n";
    cout << op.size() << "\n";
    RFOR(i, op.size()-1, 0){
        cout << op[i] << " ";
    }
    cout << "\n";

    return 0;
}