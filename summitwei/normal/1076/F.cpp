#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

ll x[MAX_N];
ll y[MAX_N];
ll n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    F0R(i, n){
        cin >> x[i];
    }
    F0R(i, n){
        cin >> y[i];
    }

    ll prevX = 0;
    ll prevY = 0;
    F0R(i, n){
        if(prevX == -1 && prevY == -1){
            break;
        }

        ll newX, newY;
        if(prevY >= 0){
            newX = x[i]-k*y[i];
        } else{
            newX = x[i]+prevX-k*y[i];
        }
        if(newX <= 0){
            if(prevX >= 0){
                if(x[i]*k >= y[i]){
                    newX = 1;
                } else{
                    newX = -1;
                }
            } else{
                if(x[i]*k >= y[i]+prevY){
                    newX = 1;
                } else{
                    newX = -1;
                }
            }
        }
        if(newX > k) newX = -1;
        
        
        if(prevX >= 0){
            newY = y[i]-k*x[i];
        } else{
            newY = y[i]+prevY-k*x[i];
        }
        if(newY <= 0){
            if(prevY >= 0){
                if(y[i]*k >= x[i]){
                    newY = 1;
                } else{
                    newY = -1;
                }
            } else{
                if(y[i]*k >= x[i]+prevX){
                    newY = 1;
                } else{
                    newY = -1;
                }
            }
        }
        if(newY > k) newY = -1;

        prevX = newX;
        prevY = newY;
        //cout << newX << " " << newY << "\n";
    }
    
    if(prevX >= 0 || prevY >= 0){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return 0;
}