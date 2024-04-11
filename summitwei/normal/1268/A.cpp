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

#define MN 200005
int n, k;
int a[MN];
int imp[MN];
int stat;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    string s;
    cin >> s;
    F0R(i, n){
        a[i] = s[i]-'0';
        if(i >= k){
            if(a[i] > a[i-k]){
                imp[i] = 1;
                if(stat == 0) stat = 1;
            }
            else if(a[i] == a[i-k]) imp[i] = 0;
            else{
                imp[i] = -1;
                if(stat == 0) stat = -1;
            }
        }
    }

    if(stat == 1){
        RFOR(i, k-1, 0){
            if(a[i] != 9){
                a[i]++;
                break;
            } else{
                a[i] = 0;
            }
        }
    }

    FOR(i, k, n-1){
        a[i] = a[i-k];
    }
    cout << n << "\n";
    F0R(i, n){
        cout << a[i];
    }
    
    return 0;
}