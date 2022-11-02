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

#define MN 260
string ans[MN][3];
bool upd(string &x, string y){
    if(x == "" || x.length()>y.length() || (x.length()==y.length() && x>y)){
        x = y;
        return true;
    } else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ans[15][0] = "x";
    ans[51][0] = "y";
    ans[85][0] = "z";
    bool bruh = true;
    while(bruh){
        bruh = false;
        F0R(i, 256){
            F0R(prio, 3){
                if(ans[i][prio] == "") continue;

                if(prio == 0){
                    if(upd(ans[255^i][0], "!"+ans[i][prio])) bruh = true;
                } else{
                    if(upd(ans[255^i][0], "!("+ans[i][prio]+")")) bruh = true;
                }

                F0R(j, 256){
                    F0R(prio2, 3){
                        if(ans[j][prio2] == "") continue;

                        //try or
                        if(upd(ans[i|j][2], ans[i][prio]+"|"+ans[j][prio2])) bruh = true;

                        //try and
                        string s = ans[i][prio];
                        if(prio > 1) s = "("+s+")";
                        
                        string t = ans[j][prio2];
                        if(prio2 > 1) t = "("+t+")";

                        if(upd(ans[i&j][1], s+"&"+t)) bruh = true;
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    F0R(_, q){
        string s;
        cin >> s;
        int bm = 0;
        F0R(i, 8){
            if(s[i] == '1') bm += (1<<(7-i));
        }
        string fin = "";
        upd(fin, ans[bm][0]);
        upd(fin, ans[bm][1]);
        upd(fin, ans[bm][2]);
        cout << fin << "\n";
    }
    
    return 0;
}