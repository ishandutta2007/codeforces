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

#define MN 100005
int a, b, c, d;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    if(a>b+1 || d>c+1){
        cout << "NO\n";
        return 0;
    }
    if(a==b+1){
        if(c != 0 || d != 0){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        F0R(i, b){
            cout << "0 1 ";
        }
        cout << "0\n";
        return 0;
    }
    if(d == c+1){
        if(a != 0 || b != 0){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        F0R(i, c){
            cout << "3 2 ";
        }
        cout << "3\n";
        return 0;
    }
    int ok = false;
    int d1 = b-a, d2 = c-d;
    if(d1 == d2+1){
        ok = true;
        cout << "YES\n";
        cout << "1 ";
        --d1;
    }
    bool ree = false;
    if(d2 == d1+1){
        ree = true;
        --d2;
    }
    if(d1 == d2){
        if(!ok){
            cout << "YES\n";
        }
        F0R(i, a){
            cout << "0 1 ";
        }
        F0R(i, d1){
            cout << "2 1 ";
        }
        F0R(i, d){
            cout << "2 3 ";
        }
        if(ree){
            cout << "2\n";
        }
    } else{
        cout << "NO\n";
    }

    return 0;
}