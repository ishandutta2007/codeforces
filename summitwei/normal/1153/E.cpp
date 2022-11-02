#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 1005
int n;
vi oc;

int que(int x1, int y1, int x2, int y2){
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();

    int res;
    cin >> res;
    return res;
}

int getbs(int loc, bool type){ //true = row, false = col
    if(type){
        int l = 1, r = n;
        while(l < r){
            int mid = (l+r)/2;

            int res = que(l, loc, mid, loc);
            if(res % 2 == 0){
                l = mid+1;
            } else{
                r = mid;
            }
        }
        assert(l == r);

        return r;
    } else{
        int l = 1, r = n;
        while(l < r){
            int mid = (l+r)/2;

            int res = que(loc, l, loc, mid);
            if(res % 2 == 0){
                l = mid+1;
            } else{
                r = mid;
            }
        }
        assert(l == r);

        return r;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    
    FOR(i, 1, n){
        int res = que(1, i, n, i);
        if(res%2 == 1){
            oc.pb(i);
        }
    }

    assert(oc.size() == 0 || oc.size() == 2); //ree
    if(oc.size() == 2){
        int loc1 = getbs(oc[0], true); //DO GETBS LATER
        int loc2 = getbs(oc[1], true);
        cout << "! " << loc1 << " " << oc[0] << " " << loc2 << " " << oc[1] << endl;
        cout.flush();
        return 0;
    }

    FOR(i, 1, n){
        int res = que(i, 1, i, n);
        if(res%2 == 1){
            oc.pb(i);
        }
    }
    assert(oc.size() == 2);

    int loc = getbs(oc[0], false);
    cout << "! " << oc[0] << " " << loc << " " << oc[1] << " " << loc << endl;
    
    
    return 0;
}