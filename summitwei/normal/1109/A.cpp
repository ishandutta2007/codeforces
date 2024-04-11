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

#define MN 300005
int n;
int nm[MN];
int px[MN];

map<int, int> appo;
map<int, int> appe;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> nm[i];
        px[i] = px[i-1]^nm[i];
        //cout << px[i] << " ";
    }
    //cout << "\n";

    ll cnt = 0;
    FOR(i, 0, n){
        if(i % 2 == 0){
            cnt += appe[px[i]];
            appe[px[i]]++;
        } else{
            cnt += appo[px[i]];
            appo[px[i]]++;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}