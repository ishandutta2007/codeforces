#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
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

#define MN 500005
int n;
int sie[MN];
void gs(int x){
    sie[1] = 1;
    FOR(i, 2, n){
        if(sie[i] == 0){
            sie[i] = i;
            for(int j=i; j<=n; j+=i){
                if(sie[j] == 0) sie[j] = i;
            }
        }
    }
}
map<int, int> amts;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    gs(n);
    FOR(i, 1, n){
        amts[i/sie[i]]++;
    }

    int cnt = 0;
    int pv = 1;
    for(auto u : amts){
        cnt += u.s;
        FOR(i, pv+1, cnt){
            cout << u.f << " ";
        }
        pv = cnt;
    }
    
    return 0;
}