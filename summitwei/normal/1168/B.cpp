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

#define MN 300005
string s;
bool chk(int l, int r){
    FOR(i, l, r-2){
        FOR(j, i+1, r){
            if((j-i)%2) continue;
            if(s[i] == s[j] && s[i] == s[(i+j)/2]) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll sm = 0;

    cin >> s;
    F0R(i, s.length()){
        FOR(j, i+1, min((int)s.length()-1, i+8)){
            sm += chk(i, j);
        }
        if(i+9 < s.length()){
            sm += (s.length()-i-9);
        }
    }

    cout << sm << "\n";
    
    return 0;
}