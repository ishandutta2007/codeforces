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

#define MN 200005
int n, s;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i];
    int cnt = 0;
    if(a[s] != 0){
        a[s] = 0;
        ++cnt;
    }
    map<int, int> cnts;
    FOR(i, 1, n){
        if(i != s){
            cnts[a[i]]++;
        }
    }
    //for(auto u : cnts) cout << u.f << " " << u.s << "\n";
    FOR(i, 1, n){
        if(!cnts.count(i)){
            //cout << "fixing " << i << "\n";
            if(cnts[0] != 0){
                ++cnt;
                --cnts[0];
            } else{
                int lst = cnts.rbegin()->f;
                //cout << "lst is " << lst << "\n";
                if(lst < i) break;
                ++cnt;
                --cnts[lst];
                if(cnts[lst] == 0){
                    cnts.erase(lst);
                }
                ++cnts[i];
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}