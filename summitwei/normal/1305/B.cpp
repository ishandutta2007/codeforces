#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
string s;
int n;
vi st, nd;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.length();

    int l = 0, r = n-1;
    while(l < r){
        if(s[l] == '(' && s[r] == ')'){
            st.pb(l+1); nd.pb(r+1);
            ++l; --r;
        } else if(s[l] == '('){
            --r;
        } else{
            ++l;
        }
    }
    if(st.size() == 0){
        cout << "0\n";
    } else{
        cout << "1\n";
        cout << st.size()*2 << "\n";
        F0R(i, st.size()) cout << st[i] << " ";
        RFOR(i, nd.size()-1, 0) cout << nd[i] << " ";
    }

    return 0;
}