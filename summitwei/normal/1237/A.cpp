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

#define MN 14000
int n;
int a[MN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int cnt = 0;
    F0R(i, n){
        cin >> a[i];
        if(a[i] % 2 != 0) ++cnt;
    }
    //cout << cnt << "\n";
    int cur = 0;
    F0R(i, n){
        if(a[i] % 2 == 0){
            cout << a[i]/2 << "\n";
        } else{
            if(cur < cnt/2){
                cout << (a[i]+1)/2;
            } else{
                cout << (a[i]-1)/2;
            }
            cout << "\n";
            ++cur;
        }
    }

    return 0;
}