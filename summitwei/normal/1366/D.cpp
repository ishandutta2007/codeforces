#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
#define MM 10000005
int n;
int a[MN];
int lp[MM+1];
vector<int> pr;
void pre(){
    for (int i=2; i<=MM-1; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=MM-1; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
pii ans[MN];
int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    pre();
    FOR(i, 1, n){
        int x=a[i];
        int y=lp[x];
        int z=x;
        while(z%y==0) z /= y;
        if(z==1){
            ans[i] = {-1, -1};
        } else{
            ans[i] = {y, z};
        }
    }
    FOR(i, 1, n){
        cout << ans[i].f << " ";
    }
    cout << "\n";
    FOR(i, 1, n){
        cout << ans[i].s << " ";
    }
    cout << "\n";
    
    return 0;
}