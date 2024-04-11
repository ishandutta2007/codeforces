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
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int x2;

int sie[MN];
void gms(){
    FOR(i, 2, MN-1){
        if(sie[i] == 0){
            for(int j=i; j<MN; j+=i){
                sie[j] = i;
            }
        }
    }
    sie[1] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x2;
    gms();
    int l = x2-sie[x2]+1;
    int mn = INF;
    FOR(i, l, x2){
        if(sie[i] == i) continue;
        mn = min(mn, i-sie[i]+1);
    }

    cout << mn << "\n";

    return 0;
}