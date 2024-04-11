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

#define MN 100005
int t;
int n;
int p[MN], ip[MN];
set<int> emp;
multiset<int> strk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        emp.clear(); strk.clear();
        cin >> n;
        emp.insert(0);
        FOR(i, 1, n){
            cin >> p[i];
            ip[p[i]] = i;
            emp.insert(i); strk.insert(1);
        }

        bool ok = true;
        FOR(i, 1, n){
            int loc = ip[i];
            set<int>::iterator ree = emp.find(loc);
            int pv = *(--ree);
            int dis = loc-pv;
            if(dis != *(--strk.end())){
                ok = false;
                break;
            }
            if(emp.upper_bound(loc) != emp.end()){
                int ot = *(emp.upper_bound(loc));
                int dis2 = ot-loc;
                strk.erase(strk.find(dis2));
                strk.insert(dis+dis2);
            }
            strk.erase(strk.find(dis));
            emp.erase(loc);
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}