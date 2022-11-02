#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
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
int n, k;
string s;
int nxt[MN][2];
int pv[MN][2];
int cur[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> s;
    int lc = 0, rc = n-1;
    while(s[lc] == s[0]) ++lc;
    --lc;
    while(s[rc] == s[n-1]) --rc;
    ++rc;

    cur[0] = n; cur[1] = n;
    RFOR(i, n-1, 0){
        cur[s[i]-'0'] = i;
        F0R(j, 2) nxt[i][j] = cur[j];
    }
    cur[0] = cur[1] = -1;
    F0R(i, n){
        cur[s[i]-'0'] = i;
        F0R(j, 2) pv[i][j] = cur[j];
    }

    if(s[0] == s[n-1]){
        int dis = rc-lc-1;
        if(k >= dis){
            cout << "tokitsukaze\n";
            return 0;
        }
    } else{
        if(max(lc, n-1-rc)+1+k >= n){
            cout << "tokitsukaze\n";
            return 0;
        }
    }

    F0R(i, n-k+1){
        int ls, rs;
        //all 0s
        if(lc < i-1 || (i != 0 && s[0] != '0')){
            ls = lc;
        } else{
            ls = nxt[i+k][1]-1;
        }
        if(rc > i+k || (i != n-k && s[n-1] != '0')){
            rs = rc;
        } else{
            rs = pv[i-1][1]+1;
        }
        bool sm;
        if(i == 0){
            if(s[n-1] == '0') sm = true;
            else sm = false;
        } else if(i == n-k){
            if(s[0] == '0') sm = true;
            else sm = false;
        } else{
            sm = (s[0] == s[n-1]);
        }
        //cout << ls << " " << rs << "\n";
        if(sm){
            int dis = rs-ls-1;
            if(k < dis){
                //cout << i << " 0\n";
                cout << "once again\n";
                return 0;
            }
        } else{
            if(max(ls, n-1-rs)+1+k < n){
                //cout << i << " 0\n";
                cout << "once again\n";
                return 0;
            }
        }

        if(lc < i-1 || (i != 0 && s[0] != '1')){
            ls = lc;
        } else{
            ls = nxt[i+k][0]-1;
        }
        if(rc > i+k || (i != n-k && s[n-1] != '1')){
            rs = rc;
        } else{
            rs = pv[i-1][0]+1;
        }

        if(i == 0){
            if(s[n-1] == '1') sm = true;
            else sm = false;
        } else if(i == n-k){
            if(s[0] == '1') sm = true;
            else sm = false;
        } else{
            sm = (s[0] == s[n-1]);
        }
        if(sm){
            int dis = rs-ls-1;
            if(k < dis){
                //cout << i << " 1\n";
                cout << "once again\n";
                return 0;
            }
        } else{
            if(max(ls, n-1-rs)+1+k < n){
                //cout << i << " 1\n";
                cout << "once again\n";
                return 0;
            }
        }
    }
    cout << "quailty\n";

    return 0;
}