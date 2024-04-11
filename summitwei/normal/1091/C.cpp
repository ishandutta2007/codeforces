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
vector<ll> good;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, sqrt(n)+EPSILON){
        if(n % i == 0){
            int j = n/i;
            //cout << i << " ";
            //jumps of j, i numbers total
            ll amt = 1LL*i*(1+(1+(i-1)*j))/2;
            cout << amt << " ";
            if(i != j){
                ll otherAmt = 1LL*j*(1+(1+(j-1)*i))/2;

                good.pb(otherAmt);
            }
        }
    }

    RFOR(i, good.size()-1, 0){
        cout << good[i] << " ";
    }

    return 0;
}