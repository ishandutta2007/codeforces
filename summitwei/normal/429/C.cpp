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

#define MN 30
int n;
int a[MN];
int ct[MN];
int sf[MN];

bool aah(int cur, int ind){
    if(ind == n){
        F0R(i, n) if(sf[i] != 0) return false;
        return true;
    }
    
    while(!ct[cur]) --cur;
    sf[ind] = cur-1;
    --ct[cur];
    F0R(i, ind){
        if(a[i] == cur+1) break;
        if(sf[i] < cur) continue;
        
        //cout << "giving " << ind << " to " << i << "\n";
        sf[i] -= cur;
        if(aah(cur, ind+1)) return true;
        sf[i] += cur;
        
        if(cur == 1) break;
    }
    ++ct[cur];
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    F0R(i, n){
        cin >> a[i];
        ++ct[a[i]];
    }
    sort(a, a+n, greater<int>() );

    if(ct[1]*2 <= n || ct[n] != 1){
        cout << "NO\n";
        return 0;
    }
    
    sf[0] = n-1;
    if(aah(n-1, 1)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}