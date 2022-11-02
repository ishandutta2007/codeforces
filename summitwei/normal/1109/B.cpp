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

#define MN 5005
string orig;
string s;
int n;
int cnt[MN];

int swp(){
    string t;
    t.resize(n);
    F0R(i, n-1){
        t[i] = s[i+1];
    }
    t[n-1] = s[0];

    s = t;
}
bool checkPali(){
    if(orig == s) return false;
    //cout << "checking " << s << "\n";

    F0R(i, n){
        if(s[i] != s[n-1-i]) return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    n = s.length();
    orig = s;
    F0R(i, n){
        cnt[s[i]-'a']++;
    }

    F0R(i, 26){
        if(cnt[i] >= n-1){
            cout << "Impossible\n";
            return 0;
        }
    }

    F0R(_, n-1){
        swp();
        if(checkPali()){
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    
    return 0;
}