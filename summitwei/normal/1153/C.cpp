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

#define MN 300005
int n;
string s;
int lct, rct;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    //n = s.length();

    if(n % 2 != 0){
        cout << ":(\n";
        return 0;
    }

    F0R(i, n){
        if(s[i] == '('){
            lct++;
        } else if(s[i] == ')'){
            rct++;
        }
    }

    int mls = n/2-lct;
    int mrs = n/2-rct;
    if(mls < 0 || mrs < 0){
        cout << ":(\n";
        return 0;
    }
    F0R(i, n){
        if(s[i] != '?') continue;

        if(mls != 0){
            s[i] = '(';
            mls--;
        } else{
            s[i] = ')';
            mrs--;
        }
    }

    int cnt = 0;
    F0R(i, n){
        if(s[i] == '(') cnt++;
        else cnt--;

        if(i != n-1 && cnt <= 0){
            cout << ":(\n";
            return 0;
        }
    }

    cout << s << "\n";
    
    return 0;
}