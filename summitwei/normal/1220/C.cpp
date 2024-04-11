#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.length();
    int mn = 27;
    F0R(i, n){
        int ree = s[i]-'a';
        if(ree > mn){
            cout << "Ann\n";
        } else{
            cout << "Mike\n";
        }
        mn = min(mn, ree);
    }

    return 0;
}