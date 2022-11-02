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

#define MN 28
#define MS 1250005
int n;
int a[MN*2];
bitset<MS> bleh[MN][MN*2];
int sm;
vi in[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        sm += a[i];
    }
    F0R(i, n){
        cin >> a[i+n];
        sm += a[i+n];
    }

    //cout << "bruhtmoo\n";
    
    sort(a, a+2*n);
    bleh[0][1][0] = true;
    FOR(i, 2, 2*n-1){
        //cout << "doing " << a[i] << "\n";
        bleh[0][i] = bleh[0][i-1];
        RFOR(j, n-1, 1){
            bleh[j][i] = bleh[j][i-1] | (bleh[j-1][i-1]<<a[i]);
            FOR(k, 0, 400){
                if(bleh[j][i][k]){
                    //cout << "reeeeeee " << i << " " << j << " " << k << "\n";
                }
            }
        }
        //cout << "ree " << i << "\n";
    }
    
    int tot = sm-a[0]-a[1];
    int wtmoo = tot/2;
    //cout << wtmoo << "\n";
    while(!bleh[n-1][2*n-1][wtmoo]){
        --wtmoo;
        //cout << wtmoo << "\n";
    }

    //cout << wtmoo << "\n";

    int cur = wtmoo;
    int cnt = n-1;
    RFOR(i, 2*n-2, 1){
        if(bleh[cnt][i][cur]){
            in[0].pb(a[i+1]);
            //cout << i << " out\n";
        } else{
            in[1].pb(a[i+1]);
            --cnt;
            cur -= a[i+1];
            // << i << " in\n";
        }
    }
    in[0].pb(a[0]);
    in[1].pb(a[1]);

    sort(in[0].begin(), in[0].end());
    sort(in[1].begin(), in[1].end(), greater<int>());

    /*int blah = tot-wtmoo;
    cout << blah+a[0]+a[1] << "\n";*/

    F0R(i, 2){
        F0R(j, n){
            cout << in[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}