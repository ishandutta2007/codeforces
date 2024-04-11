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

#define MN 5005
int n, k; ll v;
ll a[MN];
bool ree[MN][MN];
bool in[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll sm = 0;
    
    cin >> n >> k >> v;
    FOR(i, 1, n){
        cin >> a[i];
        sm += a[i];
    }
    if(sm < v){
        cout << "NO\n";
        return 0;
    }
    ree[0][0] = true;
    FOR(i, 1, n){
        F0R(j, k){
            ree[i][j] = ree[i-1][j] || ree[i-1][(j-(a[i]%k)+k)%k];
            //if(ree[i][j]) cout << "yay yay yay " << i << " " << j << "\n";
        }
    }
    if(!ree[n][v%k]){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int smh = -1;
    int smh2 = -1;
    int cur = v%k;
    RFOR(i, n-1, 0){
        if(ree[i][cur]){
            in[i+1] = false;
            smh2 = i+1;
        } else{
            in[i+1] = true;
            smh = i+1;
            //cout << i+1 << " in\n";
            cur = (cur-(a[i+1]%k)+k)%k;
        }
    }

    if(smh == -1){
        FOR(i, 2, n){
            cout << INF << " " << i << " 1\n";
        }
        if(v != 0) cout << v/k << " 1 2\n";
        return 0;
    }
    
    sm = a[smh];
    FOR(i, 1, n){
        if(i != smh && in[i]){
            cout << INF << " " << i << " " << smh << "\n";
            sm += a[i];
        }
        if(i != smh2 && !in[i]){
            cout << INF << " " << i << " " << smh2 << "\n";
        }
    }
    if(smh2 == -1){
        if(smh == 1) smh2 = 2;
        else smh2 = 1;
    }
    if(sm > v){
        cout << (sm-v)/k << " " << smh << " " << smh2 << "\n";
    } else if(sm < v){
        cout << (v-sm)/k << " " << smh2 << " " << smh << "\n";
    }

    return 0;
}