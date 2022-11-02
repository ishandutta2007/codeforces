#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
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
int cnt[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    F0R(i, s.length()){
        cnt[s[i]-'a']++;
        if(i != 0 && s[i] < s[i-1]){
            cout << "NO\n";
            return 0;
        }
    }

    if(cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0){
        cout << "NO\n";
    } else if(cnt[1] == cnt[2] || cnt[0] == cnt[2]){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }

    return 0;
}