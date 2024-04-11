#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 1000005
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n == 1 || n == 2){
        cout << "1\n";
        return 0;
    }
    int x = 4;
    while(x < n){
        if(x+1 == n){
            cout << "1\n";
            return 0;
        }
        if(x % 2 == 0){
            x = x*2+1;
        } else{
            x = x*2+2;
        }
    }
    if(x == n){
        cout << "1\n";
    } else{
        cout << "0\n";
    }
    
    return 0;
}