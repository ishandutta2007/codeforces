#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 1030
int n, k;
int sz, bl;
int nw[MN];
bool que(int x){
    cout << "? " << x << endl;
    cout.flush();
    char resp; cin >> resp;
    if(resp == 'E') exit(0);
    return resp == 'Y';
}
void clear(){
    cout << "R" << endl;
    cout.flush();
}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    memset(nw, true, sizeof nw);
 
    cin >> n >> k;
    //k = (k+1)/2;
    int blx = n/k;
    F0R(i, blx){
        int d = 0;
        clear();
        F0R(_, blx){
            int cur = (i+d+blx)%blx;
            int st = cur*k;
            FOR(j, st+1, st+k){
                if(nw[j]) if(que(j)) nw[j] = false;
            }
            if(d >= 0) ++d;
            d = -d;
        }
    }
    
    int cnt = 0;
    FOR(i, 1, n) if(nw[i]) ++cnt;
    cout << "! " << cnt << endl;
    cout.flush();

    return 0;
}