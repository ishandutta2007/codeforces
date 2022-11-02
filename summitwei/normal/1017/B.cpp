#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
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
string a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;
    int zz = 0, zo = 0, oz = 0, oo = 0;
    F0R(i, n){
        if(a[i] == '0'){
            if(b[i] == '0') ++zz;
            else ++zo;
        } else{
            if(b[i] == '0') ++oz;
            else ++oo;
        }
    }
    cout << 1LL*zz*(oz+oo)+1LL*zo*oz << "\n";
    
    return 0;
}