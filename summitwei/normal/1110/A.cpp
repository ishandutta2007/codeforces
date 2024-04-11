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

#define MN 200005


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, k;
    cin >> b >> k;
    int res = 0;
    RFOR(i, k-1, 0){
        int x;
        cin >> x;
        if((x%2) == 1 && ((b%2)!=0||i==0)){
            res = (res+1)%2;
        }
    }

    if(res){
        cout << "odd\n";
    } else{
        cout << "even\n";
    }
    
    return 0;
}