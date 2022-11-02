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
int n, m;
map<int, int> ree[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 1, n){
        ree[i][-1] = 0;
    }
    int mx = 0;
    F0R(_, m){
        int a, b, c;
        cin >> a >> b >> c;
        map<int, int>::iterator bruh = ree[a].lower_bound(c);
        --bruh;
        int val = bruh->s;
        bruh = ree[b].upper_bound(c);
        --bruh;
        if(val+1 <= bruh->s) continue;
        mx = max(mx, val+1);
        ree[b][c] = val+1;
        bruh = ree[b].find(c);
        ++bruh;
        while(bruh != ree[b].end() && bruh->s <= val+1){
            ree[b].erase(bruh);
            bruh = ree[b].find(c);
            ++bruh;
        }
    }

    cout << mx << "\n";

    return 0;
}