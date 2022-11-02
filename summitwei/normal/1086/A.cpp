#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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

#define MAX_N 300005
pii coor[3];

pii resp[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    F0R(i, 3){
        cin >> coor[i].f >> coor[i].s;
    }
    sort(coor, coor+3);

    int cnt = 0;

    FOR(i, coor[0].f, coor[1].f){
        //cout << i << " " << coor[0].s << "\n";
        resp[cnt] = mp(i, coor[0].s);
        cnt++;
    }
    if(coor[1].s > coor[0].s){
        FOR(i, coor[0].s+1, coor[1].s){
            //cout << coor[1].f << " " << i << "\n";
            resp[cnt] = mp(coor[1].f, i);
            cnt++;
        }
    } else{
        FOR(i, coor[1].s, coor[0].s-1){
            resp[cnt] = mp(coor[1].f, i);
            //cout << coor[1].f << " " << i << "\n";
            cnt++;
        }
    }

    int mn = min(coor[0].s, coor[1].s);
    int mx = max(coor[0].s, coor[1].s);

    if(coor[2].s < mn){
        RFOR(i, mn-1, coor[2].s){
            resp[cnt] = mp(coor[1].f, i);
            //cout << coor[1].f << " " << i << "\n";
            cnt++;
        }
    } else if(coor[2].s > mx){
        FOR(i, mx+1, coor[2].s){
            resp[cnt] = mp(coor[1].f, i);
            //cout << coor[1].f << " " << i << "\n";
            cnt++;
        }
    }

    FOR(i, coor[1].f+1, coor[2].f){
        resp[cnt] = mp(i, coor[2].s);
        //cout << i << " " << coor[2].s;
        cnt++;
    }

    cout << cnt << "\n";
    F0R(i, cnt){
        cout << resp[i].f << " " << resp[i].s << "\n";
    }

    return 0;
}