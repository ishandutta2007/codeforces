#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205 //check limits you incompetent ree
int n;
string a, b, c;
bool ok;
void att(string &x, string &y, char ch){
    if(ok) return;

    string ans = "";
    int i = 0, j = 0;
    while(i < 2*n && j < 2*n){
        if(x[i] == y[j] && x[i] == ch){
            ans.pb(ch);
            ++i; ++j;
        } else{
            ans.pb('0'+'1'-ch);
            if(x[i] != ch) ++i;
            if(y[j] != ch) ++j;
        }
    }
    while(i < 2*n){
        ans.pb(x[i]);
        ++i;
    }
    while(j < 2*n){
        ans.pb(y[j]);
        ++j;
    }
    if(ans.length() <= 3*n){
        cout << ans << "\n";
        ok = true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        cin >> a >> b >> c;
        ok = false;
        att(a,b,'0');
        att(a,b,'1');
        att(a,c,'0');
        att(a,c,'1');
        att(b,c,'0');
        att(b,c,'1');
    }

    return 0;
}