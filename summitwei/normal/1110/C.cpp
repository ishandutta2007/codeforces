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
#define MP 28
int q;
int p2[MP];

int lf(int x){
    FOR(i, 2, EPSILON+sqrt(x)){
        if(x % i == 0) return x/i;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p2[0] = 1;
    FOR(i, 1, MP-1){
        p2[i] = p2[i-1]*2;
    }

    cin >> q;
    F0R(_, q){
        int x;
        cin >> x;
        int bs = upper_bound(p2, p2+MP, x) - p2;
        int v = p2[bs];

        if(v-1 == x){
            cout << lf(x) << "\n";
        } else{
            cout << v-1 << "\n";
        }
    }

    return 0;
}