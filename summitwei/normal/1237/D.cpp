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

#define MN 300005
#define ML 20
int n;
int a[MN];

int lg[MN];
int tab[2][2*MN][ML];
void build(int tp){
    FOR(j, 1, ML-1){
        for(int i=1; i+(1<<j) <= 3*n; ++i){
            tab[tp][i][j] = min(tab[tp][i][j-1], tab[tp][i+(1<<(j-1))][j-1]);
        }
    }
}
int que(int l, int r, int tp){
    int j = lg[r-l+1];
    return min(tab[tp][l][j], tab[tp][r-(1<<j)+1][j]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lg[1] = 0;
    FOR(i, 2, MN-1){
        lg[i] = lg[i/2]+1;
    }
    
    int mx = 0, mn = INF;
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        a[i+n] = a[i];
        a[i+2*n] = a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mn*2 >= mx){
        F0R(_, n) cout << "-1 ";
        cout << "\n";
        return 0;
    }
    FOR(i, 1, 3*n){
        //upd(1, 1, 3*n, i, i, a[i], 1);
        tab[0][i][0] = a[i];
    }
    build(0);
    
    FOR(i, 1, 3*n){
        int l = i, r = 3*n+1;
        while(l+1 < r){
            int mid = (l+r)/2;
            //int res = que(1, 1, 3*n, i+1, mid, 1);
            int res = que(i+1, mid, 0);
            if(res*2 < a[i]){
                r = mid;
            } else{
                l = mid;
            }
        }
        //cout << i << " " << r << "\n";
        //upd(1, 1, 3*n, i, i, r, 0);
        tab[1][i][0] = r;
    }
    build(1);

    FOR(i, 1, n){
        int l = i, r = 3*n+1;
        while(l+1 < r){
            int mid = (l+r)/2;
            //int res = que(1, 1, 3*n, i, mid, 0);
            int res = que(i, mid, 1);
            if(res > mid){
                l = mid;
            } else{
                r = mid;
            }
        }
        cout << r-i << " ";
    }
    cout << "\n";
    
    return 0;
}