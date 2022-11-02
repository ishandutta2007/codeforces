#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
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

#define MN 100005
int n;
string y[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n){
        string s;
        cin >> s;
        int sm = 0;
        bool hz = false;
        int ho = 0;
        F0R(i, s.length()){
            int v = s[i]-'0';
            sm += v;
            if(v == 0){
                hz = true;
            }
            if(v % 2 == 0){
                ++ho;
            }
        }
        if(sm % 3 == 0 && hz && ho>=2){
            cout << "red\n";
        } else{
            cout << "cyan\n";
        }
    }
    
    return 0;
}