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

#define MN 505
int n, m;
int g1[MN][MN];
int g2[MN][MN];

multiset<int> arow[MN*2];
multiset<int> brow[MN*2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        F0R(j, m){
            //cin >> g1[i][j];
            int x;
            cin >> x;
            arow[i+j].insert(x);
        }
    }
    F0R(i, n){
        F0R(j, m){
            int x;
            cin >> x;
            if(arow[i+j].count(x) == 0){
                cout << "NO\n";
                return 0;
            }
            arow[i+j].erase(arow[i+j].find(x));
        }
    }
    cout << "YES\n";
    
    return 0;
}