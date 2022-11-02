#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000009
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MAX_N 1005
int n;
pll locs[MAX_N];
pll clues[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    ll sumx = 0;
    ll sumy = 0;
    F0R(i, n){
        cin >> locs[i].f >> locs[i].s;
        sumx += locs[i].f;
        sumy += locs[i].s;
    }
    F0R(i, n){
        cin >> clues[i].f >> clues[i].s;
        sumx += clues[i].f;
        sumy += clues[i].s;
    }

    cout << sumx/n << " " << sumy/n << "\n";

    return 0;
}