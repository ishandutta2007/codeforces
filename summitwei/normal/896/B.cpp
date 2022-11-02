#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000005LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n, m, c;
int arr[MN];

vi lft, rt;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n >> m >> c;
    arr[0] = 0;
    F0R(_, m){
        int cur;
        cin >> cur;
        if(cur <= c/2){
            int ok = lft.size();
            F0R(i, lft.size()){
                if(lft[i] > cur){
                    lft[i] = cur;
                    ok = i;
                    break;
                }
            }
            if(ok == lft.size()) lft.pb(cur);
            cout << ok+1 << endl;
            cout.flush();
        } else{
            int ok = rt.size();
            F0R(i, rt.size()){
                //cout << "rt " << i << " " << rt[i] << "\n";
                if(rt[i] < cur){
                    rt[i] = cur;
                    ok = i;
                    break;
                }
            }
            if(ok == rt.size()) rt.pb(cur);
            cout << n-ok << endl;
            cout.flush();
        }
        if(lft.size()+rt.size() == n) break;
    }
    
    return 0;
}