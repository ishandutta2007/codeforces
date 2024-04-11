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

#define MN 100005
int n;
int a[MN];
int b[MN];
int st[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, n){
        cin >> b[i];
        st[b[i]] = i;
    }
    int cnt = 0;
    int mx = 0;
    F0R(i, n){
        int t = st[a[i]];
        if(t < mx) ++cnt;
        mx = max(mx, t);
    }
    cout << cnt << "\n";
    
    return 0;
}