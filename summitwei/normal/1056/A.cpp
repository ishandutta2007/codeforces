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
#define MAX_N 105
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int times[MAX_N];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        int r;
        cin >> r;
        F0R(j, r){
            int x;
            cin >> x;
            times[x]++;
        }
    }

    FOR(i, 1, 100){
        if(times[i] == n){
            cout << i << " ";
        }
    }
    
    return 0;
}