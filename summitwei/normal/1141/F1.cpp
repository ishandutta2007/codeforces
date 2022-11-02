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
 
#define MN 1505
int n;
int a[MN];
map<int, vpii> ree;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(j, 1, n){
        int sm = 0;
        RFOR(i, j, 1){
            sm += a[i];
            //cout << i << " " << j << " " << sm << "\n";
            if(ree[sm].empty()){
                ree[sm].pb({i, j});
            } else{
                pii lst = *(--ree[sm].end());
                if(i > lst.s){
                    ree[sm].pb({i, j});
                }   
            }
        }
    }
    
    int msz = 0, msm = 0;
    for(auto u : ree){
        if(u.s.size() > msz){
            msz = u.s.size();
            msm = u.f;
        }
    }
    cout << msz << "\n";
    for(auto u : ree[msm]){
        cout << u.f << " " << u.s << "\n";
    }
    //cout << "hmm\n";
 
    return 0;
}