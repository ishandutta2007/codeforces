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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n, q;
bool aah[2][MN];
int bad;
int r, c;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> q;
    F0R(i, q){
        cin >> r >> c;
        --r;
        if(aah[r][c]){
            aah[r][c] = false;
            if(aah[1-r][c-1] == true) --bad;
            if(aah[1-r][c] == true) --bad;
            if(aah[1-r][c+1] == true) --bad;
        } else{
            aah[r][c] = true;
            if(aah[1-r][c-1] == true) ++bad;
            //cout << bad;
            if(aah[1-r][c] == true) ++bad;
            //cout << bad;
            if(aah[1-r][c+1] == true){
                //cout << 1-r << " " << c+1 << " okay\n";
                ++bad;
            }
            //cout << bad;
        }
        //cout << bad << "\n";
        if(bad == 0){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
 
        /*F0R(i, 2){
            FOR(j, 0, n){
                cout << aah[i][j] << " ";
            }
            cout << "\n";
        }*/
    }
 
    return 0;
}