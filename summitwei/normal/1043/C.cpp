#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

bool toSw[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool isSw = false;
    RFOR(i, s.length()-1, 0){
        if(s[i] == 'a' && !isSw){
            //we want this at front
            toSw[i] = true;
            isSw = true;
        } else if(s[i] == 'b' && isSw){
            //we want this at back
            toSw[i] = true;
            isSw = false;
        }
    }

    F0R(i, s.length()){
        if(toSw[i]) cout << "1 ";
        else cout << "0 ";
    }
    
    return 0;
}