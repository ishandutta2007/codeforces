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

#define MN 500005
int n;
int top, scd;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    char c;
    int x, y;
    F0R(i, n){
        cin >> c >> x >> y;
        if(c == '+'){
            if(x > y) swap(x, y);
            top = max(top, x);
            scd = max(scd, y);
        } else{
            if(x > y) swap(x, y);

            if(x < top || y < scd){
                cout << "NO\n";
            } else{
                cout << "YES\n";
            }
        }
    }

    return 0;
}