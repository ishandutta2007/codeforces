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

#define MN 200005
string s, t;

bool isVowel(char c){
    if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    if(s.length() != t.length()){
        cout << "No\n";
        return 0;
    }
    F0R(i, s.length()){
        if(isVowel(s[i]) != isVowel(t[i])){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    
    return 0;
}