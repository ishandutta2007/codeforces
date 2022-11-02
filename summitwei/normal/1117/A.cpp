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

#define MN 100005
int n;
int a[MN];
int mx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0;
    
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ms = 0;
    int cs = 0;
    FOR(i, 1, n){
        if(a[i] == mx) cs++;
        else cs = 0;
        ms = max(cs, ms);
    }

    cout << ms << "\n";

    return 0;
}