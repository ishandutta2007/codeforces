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

#define MN 2005
#define ML 11
int n;
int a[MN], b[MN];
int dist[MN][ML][MN]; //i think there are less than 2000?

map<int, int> ree; //states after comp
//int spc[MN]; //# of spaces
int leav[MN][ML]; //after leaving someone here
int pick[MN][ML]; //after picking someone to here

priority_queue<pair<pii, pii> > pq; //dist, #ppl, floor, state
int dijk(){
    int cur = 0;
    int st = 0;
    while(a[cur] == 1 && pick[st][0] != -1){
        st = pick[st][b[cur]];
        ++cur;
    }
    pq.push({{-cur, cur}, {1, st}});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int dis = -top.f.f; int ppl = top.f.s; int fl = top.s.f; int st = top.s.s;
        if(dist[ppl][fl][st] != -1) continue;
        //cout << ppl << " " << fl << " " << st << " " << dis << "\n";
        if(ppl == n && st == 0) return dis;
        dist[ppl][fl][st] = dis;

        FOR(j, 1, 9){
            if(fl == j) continue;
            int d = dis;
            int nst = st;
            int cl = ppl;
            if(fl < j){
                d += (j-fl);
            } else{
                d += (fl-j);
            }
            bool did = false;
            //cout << "checking " << j << "\n";
            while(leav[nst][j] != -1){
                //cout << nst << " drops off " << j << " and becomes " << leav[nst][j] << "\n";
                nst = leav[nst][j];
                ++d;
                did = true;
            }
            while(a[cl] == j && pick[nst][0] != -1){
                //cout << nst << " picks up " << cl << " and becomes " << pick[nst][b[cl]] << "\n";
                nst = pick[nst][b[cl]];
                ++d;
                ++cl;
                did = true;
            }

            if(did) pq.push({{-d, cl}, {j, nst}});
        }
    }
    return -1;
}

int p10[4] = {1, 10, 100, 1000};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dist, -1, sizeof dist);

    cin >> n;
    F0R(i, n){
        cin >> a[i] >> b[i];
    }

    int cnt = 0;
    F0R(i, 10000){
        int bruh[4] = {i%10, (i/10)%10, (i/100)%10, i/1000};
        if(bruh[0] > bruh[1] || bruh[1] > bruh[2] || bruh[2] > bruh[3]){
            continue;
        }
        ree[i] = cnt;
        //F0R(j, 4) if(bruh[j] == 0) ++spc[cnt];
        //cout << i << " " << cnt << "\n";
        ++cnt;
    }
    F0R(i, 10000){
        int bruh[4] = {i%10, (i/10)%10, (i/100)%10, i/1000};
        if(bruh[0] > bruh[1] || bruh[1] > bruh[2] || bruh[2] > bruh[3]){
            sort(bruh, bruh+4);
            int res = bruh[0]+bruh[1]*10+bruh[2]*100+bruh[3]*1000;
            ree[i] = ree[res];
            continue;
        }
    }
    F0R(i, 10000){
        int bruh[4] = {i%10, (i/10)%10, (i/100)%10, i/1000};
        if(bruh[0] > bruh[1] || bruh[1] > bruh[2] || bruh[2] > bruh[3]){
            continue;
        }
        int cur = ree[i];

        if(bruh[0] == 0){
            FOR(j, 1, 9){
                pick[cur][j] = ree[i+j];
                //cout << i << " " << cur << " " << j << " " << ree[i+j] << "\n";
            }
        } else{
            pick[cur][0] = -1;
            //cout << i << " " << cur << " can't pick\n";
        }
        FOR(j, 1, 9){
            int val = i;
            F0R(k, 4){
                if(bruh[k] == j){
                    val -= p10[k]*j;
                    break;
                }
            }
            if(val == i) leav[cur][j] = -1;
            else leav[cur][j] = ree[val];
        }
    }

    cout << dijk() << "\n";

    return 0;
}