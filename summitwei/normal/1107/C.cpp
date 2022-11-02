#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, k;
ll dam[MN];
ll ps[MN];
string s;

vi v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    FOR(i, 1, n){
        cin >> dam[i];
        ps[i] = ps[i-1]+dam[i];
    }
    cin >> s;

    ll sum = 0;

    char c;
    FOR(i, 1, n){
        if(i == 1){
            c = s[i-1];
        }

        if(s[i-1] != c){
            //cout << "new at " << i << "\n";
            sort(v.begin(), v.end(), greater<int>());
            F0R(j, min(k, (int)v.size())){
                sum += v[j];
                //cout << "adding " << v[j] << "\n";
            }
            v.clear();
            c = s[i-1];
        }

        v.pb(dam[i]);
    }

    sort(v.begin(), v.end(), greater<int>());
    F0R(j, min(k, (int)v.size())){
        sum += v[j];
    }

    cout << sum << "\n";

    return 0;
}