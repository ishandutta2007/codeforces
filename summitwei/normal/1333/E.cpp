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

#define MN 505
int n;
int gr[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n <= 2){
        cout << "-1\n";
        return 0;
    }
    gr[1][1] = 7; gr[1][2] = 6; gr[1][3] = 9;
    gr[2][1] = 8; gr[2][2] = 3; gr[2][3] = 4;
    gr[3][1] = 1; gr[3][2] = 2; gr[3][3] = 5;
    FOR(i, 4, n){
        FOR(j, 1, i-1){
            FOR(k, 1, i-1){
                gr[j][k] += 2*i-1;
            }
        }
        if(i % 2 == 0){
            FOR(j, 1, i){
                gr[j][i] = j;
            }
            RFOR(j, i-1, 1){
                gr[i][j] = i*2-j;
            }
        } else{
            FOR(j, 1, i){
                gr[i][j] = j;
            }
            RFOR(j, i-1, 1){
                gr[j][i] = i*2-j;
            }
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            cout << gr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}