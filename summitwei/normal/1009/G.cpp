#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n; int cnt[6];
int bms[MN];
int reqs[1<<6];

bool chk(){
    F0R(i, 1<<6){
        int amt = 0;
        F0R(j, 6) if(i&(1<<j)) amt += cnt[j];
        if(amt < reqs[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    n = s.length();
    F0R(i, n) cnt[s[i]-'a']++;
    int m;
    cin >> m;
    F0R(i, m){
        int x; string t;
        cin >> x >> t;
        int bm = 0;
        F0R(j, t.length()){
            bm += 1<<(t[j]-'a');
        }
        bms[x] = bm;
    }
    FOR(i, 1, n){
        if(bms[i] == 0) bms[i] = 63;
        F0R(j, 1<<6){
            if((bms[i]&j)==bms[i]){
                ++reqs[j];
            }
        }
        //cout << bms[i] << " ";
    }
    //cout << "\n";
    if(!chk()){
        cout << "Impossible\n";
        return 0;
    }
    string ans = "";
    FOR(i, 1, n){
        //F0R(j, 1<<6) cout << reqs[j] << " ";
        //cout << "\n";
        int cbm = bms[i];
        F0R(j, 1<<6) if((cbm&j)==cbm) --reqs[j];
        F0R(j, 6) if((cbm & (1<<j)) && cnt[j] != 0){
            //cout << "checking " << i << " " << (char)('a'+j) << "\n";
            --cnt[j];
            if(chk()){ ans += (char)('a'+j); break; }
            ++cnt[j];
        }
    }
    cout << ans << "\n";
    
    return 0;
}