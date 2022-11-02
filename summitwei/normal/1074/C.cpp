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
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
pii coords[MAX_N];
int minX, minY, maxX, maxY;
int ur, ul, dr, dl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    F0R(i, N){
        int x, y;
        cin >> x >> y;
        if(i == 0){
            minX = x;
            maxX = x;
            minY = y;
            maxY = y;

            ur = x+y;
            dl = -x-y;
            ul = -x+y;
            dr = x-y;
        }

        minX = min(x, minX);
        minY = min(y, minY);
        maxX = max(x, maxX);
        maxY = max(y, maxY);

        ur = max(ur, x+y);
        dl = max(dl, -x-y);
        ul = max(ul, -x+y);
        dr = max(dr, x-y);
    }

    int fourAns = maxX + maxY - minX - minY;
    int threeAns = max(max(-minX-minY+ur, maxX+maxY+dl), max(-minX+maxY+dr, maxX-minY+ul));

    cout << threeAns*2 << " ";
    FOR(i, 4, N){
        cout << fourAns*2 << " ";
    }
    

    return 0;
}