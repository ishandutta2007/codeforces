#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n;
int a[MN];

int sie[MN];
int mob[MN];
void gms(){
    FOR(i, 2, MN-1){
        if(sie[i] == 0){
            for(int j=i; j<MN; j+=i){
                sie[j] = i;
            }
        }
    }
    sie[1] = 1;
    mob[1] = 1;
    FOR(i, 2, MN-1){
        int cnt = 0;
        int x = i;
        while(x != 1){
            int fac = sie[x];
            x /= fac;
            if(x % fac == 0){
                mob[i] = 0;
                break;
            }
            ++cnt;
        }
        if(x == 1){
            if(cnt % 2 == 0){
                mob[i] = 1;
            } else{
                mob[i] = -1;
            }
        }
    }
}

vi bleh[MN];
set<pii> hmm;
vi e[MN];

int d[MN];
int p[MN];
queue<int> ree;
int bfs(int x){
    //cout << "doing " << x << "\n";
    memset(d, -1, sizeof d);
    memset(p, -1, sizeof p);
    d[x] = 0;
    ree.push(x);
    int ans = INF;
    while(!ree.empty()){
        int cn = ree.front();
        ree.pop();

        //cout << cn << " dist " << d[cn] << "\n";

        for(auto nn : e[cn]){
            if(d[nn] == -1){
                d[nn] = d[cn]+1;
                p[nn] = cn;
                ree.push(nn);
            } else if(nn != p[cn]){
                ans = min(ans, d[cn]+d[nn]+1);
            }
        }
    }
    //cout << "got " << ans << "\n";
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    gms();

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        int x = a[i];
        while(x != 1){
            int fac = sie[x];
            int cnt = 0;
            while(x % fac == 0){
                x /= fac;
                ++cnt;
            }
            cnt %= 2;
            if(cnt == 1){
                bleh[i].pb(fac);
                //cout << i << " fac " << fac << "\n";
            }
        }
        if(bleh[i].size() == 0){
            cout << "1\n";
            return 0;
        }
    }
    FOR(i, 1, n){
        if(bleh[i].size() == 1){
            if(hmm.count({bleh[i][0], 1})){
                //cout << i << " dbl\n";
                cout << "2\n";
                return 0;
            } else{
                hmm.insert({bleh[i][0], 1});
                e[bleh[i][0]].pb(1);
                e[1].pb(bleh[i][0]);
            }
        } else{
            if(bleh[i][0] > bleh[i][1]) swap(bleh[i][0], bleh[i][1]);
            if(hmm.count({bleh[i][0], bleh[i][1]})){
                //cout << i << " dbld\n";
                cout << "2\n";
                return 0;
            } else{
                hmm.insert({bleh[i][0], bleh[i][1]});
                e[bleh[i][0]].pb(bleh[i][1]);
                e[bleh[i][1]].pb(bleh[i][0]);
            }
        }
    }
    int ans = INF;
    for(int i=1; i<=1000; ++i){
        ans = min(ans, bfs(i));
    }

    if(ans == INF) ans = -1;
    cout << ans << "\n";

    return 0;
}