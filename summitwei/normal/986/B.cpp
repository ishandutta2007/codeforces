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
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n;
int p[MN];
bool fd[MN];
int dfs(int cn){
    if(fd[cn]) return 0;
    fd[cn] = true;
    return 1+dfs(p[cn]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> p[i];
    }
    int sm = 0;
    FOR(i, 1, n){
        if(!fd[i]){
            sm += (dfs(i)-1);
        }
    }

    if(n % 2 == sm % 2){
        cout << "Petr\n";
    } else{
        cout << "Um_nik\n";
    }

    return 0;
}