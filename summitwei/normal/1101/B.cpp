#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    
    int lstat = 0;
    int rstat = 0;
    int l = INF, r = -INF;
    F0R(i, s.length()){
        char c = s[i];
        if(c == '['){
            lstat = 1;
        }
        if(c == ':' && lstat == 1){
            l = i;
            break;
        }
    }

    RFOR(i, s.length()-1, 0){
        char c = s[i];
        if(c == ']'){
            rstat = 1;
        }
        if(c == ':' && rstat == 1){
            r = i;
            break;
        }
    }

    if(l >= r){
        cout << "-1\n";
        return 0;
    }
    int cnt = 0;
    FOR(i, l, r){
        char c = s[i];
        if(c == '|') cnt++;
    }

    cout << cnt+4 << "\n";

    return 0;
}