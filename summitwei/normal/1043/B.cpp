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
#define MAX_N 1005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int a[MAX_N];
int x[MAX_N];
int n;

bool works[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }

    int okcount = 0;

    FOR(i, 1, n){
        F0R(j, i){
            x[j] = a[j+1]-a[j];
        }

        bool ok = true;
        FOR(j, 1, n){
            if(a[j] != x[(j+i-1) % i] + a[j-1]){
                ok = false;
                break;
            }
        }
        if(ok) okcount++;
        works[i] = ok;
    }

    cout << okcount << "\n";
    FOR(i, 1, n){
        if(works[i]) cout << i << " ";
    }

    return 0;
}