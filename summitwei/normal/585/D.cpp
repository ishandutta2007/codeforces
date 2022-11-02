#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 30
int n;
struct Task{
    int l, m, w;
    int lm;
    int lw;
};

Task tasks[MN];

map<pii, pii> a;
void genA(int cur, int l, int m, int w, int s){
    //cout << "proc " << cur << " " << l << " " << m << " " << w << "\n";
    if(cur == n/2){
        if(!a.count(mp(l-m, l-w))){
            a.insert(mp(mp(l-m, l-w), mp(l, s)));
        } else{
            a[mp(l-m, l-w)] = max(a[mp(l-m, l-w)], mp(l, s));
        }
        return;
    }

    genA(cur+1, l+tasks[cur].l, m+tasks[cur].m, w, s*4+0);
    genA(cur+1, l, m+tasks[cur].m, w+tasks[cur].w, s*4+1);
    genA(cur+1, l+tasks[cur].l, m, w+tasks[cur].w, s*4+2);
}

map<pii, pii> b;
void genB(int cur, int l, int m, int w, int s){
    //cout << "proc " << cur << " " << l << " " << m << " " << w << " " << s << "\n";
    if(cur == n){
        //cout << "proc " << cur << " " << l << " " << m << " " << w << " " << s << "\n";
        //a.pb(mp(l-m, l-w), l);
        if(!b.count(mp(l-m, l-w))){
            b.insert(mp(mp(l-m, l-w), mp(l, s)));
        } else{
            b[mp(l-m, l-w)] = max(b[mp(l-m, l-w)], mp(l, s));
        }
        return;
    }

    genB(cur+1, l+tasks[cur].l, m+tasks[cur].m, w, s*4+0);
    genB(cur+1, l, m+tasks[cur].m, w+tasks[cur].w, s*4+1);
    genB(cur+1, l+tasks[cur].l, m, w+tasks[cur].w, s*4+2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> tasks[i].l >> tasks[i].m >> tasks[i].w;
        tasks[i].lm = tasks[i].l - tasks[i].m;
        tasks[i].lw = tasks[i].l - tasks[i].w;
    }

    genA(0, 0, 0, 0, 0);
    genB(n/2, 0, 0, 0, 0);

    int ans = -INF;
    pii resp = mp(0, 0);
    for(auto u : a){
        int lm = u.first.first;
        int lw = u.first.second;

        if(b.count(mp(-lm, -lw))){
            pair<int, int> bval = b[mp(-lm, -lw)];
            //cout << u.second.first << " " << u.second.second << " " << bval.f << " " << bval.s << "\n";
            int tot = u.second.first + bval.f;

            if(tot > ans){
                ans = tot;
                resp = mp(u.second.second, bval.s);
            }
        }
    }
    
    if(ans == -INF) cout << "Impossible\n";
    else{
        //cout << resp.f << " " << resp.s << "\n";
        string op;
        F0R(i, n/2){
            //cout << ((resp.f & (1<<(2*(n/2-i)))) > 0) << " " << 2*((resp.f&(1<<(2*(n/2-i)+1))) > 0) << " ";
            int res = ((resp.f & (1<<(2*(n/2-1-i)))) > 0)+2*((resp.f&(1<<(2*(n/2-1-i)+1))) > 0);
            //cout << res << " ";
            if(res == 0){
                op += "LM\n";
            } else if(res == 1){
                op += "MW\n";
            } else{
                op += "LW\n";
            }
        }
        //cout << op << "\n";
        FOR(i, n/2, n-1){
            //cout << (resp.s & (1<<(2*(n-1-i)))) << " " << (resp.s&(1<<(2*(n-1-i)+1))) << "\n";
            int res = ((resp.s & (1<<(2*(n-1-i))))>0)+2*((resp.s&(1<<(2*(n-1-i)+1)))>0);
            //cout << res << "\n";
            if(res == 0){
                op += "LM\n";
            } else if(res == 1){
                op += "MW\n";
            } else{
                op += "LW\n";
            }
        }
        
        cout << op;
    }

    return 0;
}