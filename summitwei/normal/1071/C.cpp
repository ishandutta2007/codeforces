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
#define MO 13
int n;
int a[MN];
int d[1<<MO];
int pv[1<<MO];
queue<int> q;
void bfs(int k, bool tp){
    memset(d, 0x3f, sizeof d);
    if(tp){
        F0R(i, 1<<5){
            d[i] = 0;
            q.push(i);
        }
    } else{
        d[0] = 0;
        q.push(0);
    }
    int mxd = 0;
    //int cnt = 0;
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        F0R(i, k){
            FOR(j, 1, k){
                int a = i-j, b = i, c = i+j;
                if(a < 0 || c >= k) continue;
                int nn = cn;
                nn ^= ((1<<a)+(1<<b)+(1<<c));
                if(d[nn] == INF){
                    //cout << nn << " from " << cn << "\n";
                    pv[nn] = cn;
                    d[nn] = d[cn]+1;
                    //++cnt;
                    mxd = d[nn];
                    //cout << nn << " " << d[nn] << "\n";
                    //cout << "found " << nn << "\n";
                    q.push(nn);
                }
            }
        }
    }
    //cout << cnt << "\n";
    //cout << mxd << "\n";
}

vector<int> ree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }

    bfs(11, true);
    int cur = n;
    while(cur >= 11){
        int st = cur-11;
        int sm = 0;
        F0R(i, 11){
            if(a[st+i]) sm += (1<<i);
        }
        //cout << sm << " " << d[sm] << "\n";
        while(d[sm] != 0){
            int dif = sm ^ pv[sm];
            //cout << "at " << sm << " and dif is " << dif << " to " << pv[sm] << "\n";
            F0R(i, 11){
                if(dif & (1<<i)){
                    ree.pb(st+i+1);
                    a[st+i] = 1-a[st+i];
                }
            }
            sm = pv[sm];
        }
        cur -= 6;
    }


    /*int mxd = bfs();
    cout << mxd << "\n";*/
    //bfs(min(9, n));
    //bfs(11, true);
    n = min(10, n);
    bfs(n, false);
    int sm = 0;
    F0R(i, n){
        if(a[i]) sm += (1<<i);
    }
    if(d[sm] == INF){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        while(sm != 0){
            int dif = sm ^ pv[sm];
            //cout << "at " << sm << " and dif is " << dif << " to " << pv[sm] << "\n";
            F0R(i, n){
                if(dif & (1<<i)){
                    ree.pb(i+1);
                }
            }
            sm = pv[sm];
        }

        cout << ree.size()/3 << "\n";
        F0R(i, ree.size()){
            cout << ree[i] << " ";
            if(i % 3 == 2) cout << "\n";
        }
    }

    return 0;
}