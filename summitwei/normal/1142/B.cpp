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

#define MN 200005
#define ML 20
int n, m, q;
int p[MN];
int a[MN];
int pv[MN];

int cur[MN];
int prv[MN];

int dp[MN][ML];
int res[MN];
void dodp(){
    F0R(i, m){
        dp[i][0] = prv[i];
    }
    FOR(i, 1, ML-1){
        F0R(j, m){
            if(dp[j][i-1] == -1) dp[j][i] = -1;
            else dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
}
int up(int loc, int amt){
    //if(amt <= 0) return loc;
    int cl = loc;
    RFOR(i, ML-1, 0){
        if(amt & (1<<i)){
            amt -= (1<<i);
            cl = dp[cl][i];
        }
        if(cl == -1) return -1;
    }
    return cl;
}
void getres(){
    F0R(i, m){
        /*int upn = up(i, n-1);
        //cout << i << " up " << n << " is " << upn << "\n";
        if(upn != up(i, n-2)){
            res[i] = upn;
        } else{
            upn = -1;
        }*/
        res[i] = up(i, n-1);
    }
}

//pii res[MN];

/*struct Que{
    int l, r;
    int ind;
};
bool comp(Que a, Que b){
    if(a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}
Que ques[MN];
bool ans[MN];*/

int mxes[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    F0R(i, n){
        cin >> p[i];
    }
    F0R(i, m){
        cin >> a[i];
    }
    F0R(i, n){
        pv[p[(i+1)%n]] = p[i];
    }
    /*FOR(i, 1, n){
        cout << "next after " << i << " is " << nv[i] << "\n";
        cout << "prev was " << pv[i] << "\n";
    }*/

    memset(cur, -1, sizeof cur);
    memset(prv, -1, sizeof prv);

    F0R(i, m){
        int c = a[i];
        cur[c] = i;
        /*if(cur[pv[c]] >= 0){
            prv[i] = cur[pv[c]];
        }*/
        prv[i] = cur[pv[c]];
    }
    /*F0R(i, m){
        cout << prv[i] << " ";
    }
    cout << "\n";*/

    /*F0R(i, m){
        if(prv[i] < 0){
            res[i] = mp(1, i);
        } else{
            int pl = prv[i];
            res[i] = mp(res[pl].f+1, res[pl].s);
            if(res[i].f > n){
                res[i].f--;
                res[i].s = nxt[res[i].s];
            }
        }
        //cout << res[i].f << " " << res[i].s << "\n";
    }*/
    dodp();
    getres();
    /*F0R(i, m){
        cout << res[i] << " ";
    }
    cout << "\n";*/
    int curmx = -1;
    F0R(i, m){
        curmx = max(curmx, res[i]);
        mxes[i] = curmx;
    }

    F0R(i, q){
        int l, r;
        cin >> l >> r;
        l--; r--;

        if(mxes[r] >= l){
            cout << "1";
        } else{
            cout << "0";
        }
    }

    /*F0R(i, q){
        cin >> ques[i].l >> ques[i].r;
        ques[i].l--;
        ques[i].r--;
        ques[i].ind = i;
    }
    sort(ques, ques+q, comp);

    int curmx = -1;
    int on = 0;
    F0R(i, m){
        curmx = max(curmx, res[i]);
        while(on < q && ques[on].r == i){
            ans[ques[on].ind] = (curmx >= ques[on].l);
            on++;
        }
    }

    F0R(i, q){
        cout << ans[i];
    }*/
    
    return 0;
}