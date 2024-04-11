#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pll> vpll;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 400005
int t;
int n, a[MN], cnt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        int cur = 0;
        cin >> n;
        F0R(i, n){
            cin >> a[i];
            if(i != 0 && a[i] != a[i-1]) ++cur;
            ++cnt[cur];
        }
        int s = 0, b = 0;
        FOR(i, 1, cur){
            if(s > cnt[0]){
                b += cnt[i];
                if(cnt[0]+s+b > n/2){
                    b -= cnt[i];
                    break;
                }
            } else{
                s += cnt[i];
            }
        }

        if(cnt[0] >= s || cnt[0] >= b){
            cout << "0 0 0\n";
        } else{
            cout << cnt[0] << " " << s << " " << b << "\n";
        }

        F0R(i, n) a[i] = 0;
        F0R(i, cur+1) cnt[i] = 0;
    }

    return 0;
}