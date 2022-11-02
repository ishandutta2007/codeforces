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
#define MAX_N 100005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N, M;
int verts[MAX_N];
int vertCt[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    F0R(i, N){
        cin >> verts[i];
    }
    sort(verts, verts+N);

    int total = 0;
    F0R(i, M){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(x1 != 1) continue;

        if(x2 == INF){
            total++;
            continue;
        }

        int bs = upper_bound(verts, verts+N, x2) - verts;
        vertCt[bs]++;
        total++;
    }

    int currAns = total - vertCt[0];
    int minAns = currAns;
    //cout << "at 0 there are " << vertCt[0] << " and " << currAns << " steps needed\n";
    FOR(i, 1, N){
        //cout << "at " << i << " there are " << vertCt[i] << " and " << currAns << " steps needed\n";
        currAns = currAns+1-vertCt[i];
        minAns = min(minAns, currAns);
    }

    cout << minAns << "\n";
    return 0;
}