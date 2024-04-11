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
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n, m;
ll l;
ll hl[MAX_N];
int numSegs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    numSegs = 0;

    cin >> n >> m >> l;
    F0R(i, n){
        cin >> hl[i];
        if(hl[i] > l){
            if(i == 0 || hl[i-1] <= l) numSegs++;
        }
    }

    F0R(i, m){
        int q;
        cin >> q;
        if(q == 0){
            cout << numSegs << "\n";
        } else{
            int p;
            ll d;
            cin >> p >> d;
            p--;
            if(hl[p] <= l && hl[p]+d > l){
                if(p == 0){
                    if(hl[1] <= l) numSegs++;
                } else if(p == n-1){
                    if(hl[n-2] <= l) numSegs++;
                } else{
                    if(hl[p-1] <= l && hl[p+1] <= l) numSegs++;
                    else if(hl[p-1] > l && hl[p+1] > l) numSegs--;
                }
            }
            hl[p] += d;
        }
    }

    return 0;
}