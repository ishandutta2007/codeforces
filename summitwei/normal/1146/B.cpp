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

#define MN 100005
string s;
string t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    int cur = 0;
    s.resize(t.length());
    F0R(i, t.length()){
        if(t[i] != 'a'){
            s[cur] = t[i];
            cur++;
        }
    }
    //cout << s << "\n";
    if(cur % 2 != 0){
        cout << ":(\n";
        return 0;
    }
    
    if(s.substr(0, cur/2) != s.substr(cur/2, cur/2)){
        cout << ":(\n";
        return 0;
    }
    if(t.substr(t.length()-cur/2, cur/2) != s.substr(0, cur/2)){
        cout << ":(\n";
        return 0;
    }

    cout << t.substr(0, t.length()-cur/2) << "\n";
    
    return 0;
}