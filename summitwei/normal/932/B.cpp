#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int q;
int ree[MN];
int ps[MN][10];

int bruh(int x){
    if(x < 10) return x;
    if(ree[x] != 0) return ree[x];
    //cout << "x " << x << " ";
    int pro = 1;
    while(x > 0){
        int o = x%10;
        if(o != 0) pro *= o;
        x /= 10;
    }
    //cout << "pro " << pro << "\n";
    ree[x] = bruh(pro);
    return ree[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 1, MN-1){
        int o = bruh(i);
        //cout << i << " " << o << "\n";
        F0R(j, 10){
            ps[i][j] = ps[i-1][j];
            if(j == o) ps[i][j]++;
        }
    }
    cin >> q;
    F0R(_, q){
        int l, r, k;
        cin >> l >> r >> k;
        cout << ps[r][k] - ps[l-1][k] << "\n";
    }

    return 0;
}