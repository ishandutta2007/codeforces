#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
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
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int t;
int n;
int osm[MN];
int cc[MN];
int finc[MN];
int sm[MN][2];
int col[MN];
vi arrs[3];
vpii chk;

void que(int type){
    if(chk.size() == 0) return;
    cout << "Q " << chk.size() << " ";
    F0R(i, chk.size()){
        cout << chk[i].f << " " << chk[i].s << " ";
    }
    cout << "\n";
    cout.flush();
    string s;
    cin >> s;
    if(s == "-1") exit(0);
    F0R(i, chk.size()){
        if(type == 0){
            osm[chk[i].s] = s[i]-'0';
        } else if(type == 1){
            sm[cc[chk[i].s]][0] = s[i]-'0';
        } else{
            sm[cc[chk[i].s]][1] = s[i]-'0';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    F0R(_, t){
        cin >> n;
        if(n == -1) exit(0);
        
        F0R(i, 3){
            arrs[i].clear();
        }
        
        chk.clear();
        FOR(i, 1, n-1){
            if(i % 2 == 1){
                chk.pb(mp(i, i+1));
            }
        }
        que(0);
        
        chk.clear();
        FOR(i, 1, n-1){
            if(i % 2 == 0){
                chk.pb(mp(i, i+1));
            }
        }
        que(0);
        
        int ccc = 1;
        cc[1] = 1;
        finc[1] = 1;
        FOR(i, 2, n){
            if(osm[i]){
                cc[i] = ccc;
            } else{
                ccc++;
                cc[i] = ccc;
                finc[ccc] = i;
            }
        }
        
        chk.clear();
        FOR(i, 1, ccc-1){
            if(i % 2 == 1){
                chk.pb(mp(finc[i], finc[i+1]));
            }
        }
        que(1);
        
        chk.clear();
        FOR(i, 1, ccc-1){
            if(i % 2 == 0){
                chk.pb(mp(finc[i], finc[i+1]));
            }
        }
        que(1);
        
        
        chk.clear();
        FOR(i, 1, ccc-2){
            if(i % 4 < 2){
                chk.pb(mp(finc[i], finc[i+2]));
            }
        }
        que(2);
        
        chk.clear();
        FOR(i, 1, ccc-2){
            if(i % 4 >= 2){
                chk.pb(mp(finc[i], finc[i+2]));
            }
        }
        que(2);
        
        col[1] = 0;
        col[2] = 1;
        FOR(i, 3, ccc){
            if(sm[i][1]){
                col[i] = col[i-2];
            } else{
                col[i] = 3-col[i-1]-col[i-2];
            }
        }
        
        FOR(i, 1, n){
            int c = col[cc[i]];
            arrs[c].pb(i);
        }
        
        cout << "A " << arrs[0].size() << " " << arrs[1].size() << " " << arrs[2].size() << "\n";
        F0R(i, 3){
            F0R(j, arrs[i].size()){
                cout << arrs[i][j] << " ";
            }
            cout << "\n";
        }
        cout.flush();
    }
    
    return 0;
}