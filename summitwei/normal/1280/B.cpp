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

#define MN 65
int t;
int r, c;
char gr[MN][MN];
int rc[MN], cc[MN];
int cnt;
int res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    res = 4;

    cin >> t;
    F0R(_, t){
        cin >> r >> c;
        F0R(i, r){
            F0R(j, c){
                cin >> gr[i][j];
                if(gr[i][j] == 'A'){
                    ++cnt;
                    ++rc[i];
                    ++cc[j];
                    if(rc[i] == c){
                        if(i == 0 || i == r-1) res = 1;
                        else res = min(res, 2);
                    }
                    if(cc[j] == r){
                        if(j == 0 || j == c-1) res = 1;
                        else res = min(res, 2);
                    }
                    if(i == 0 || j == 0 || i == r-1 || j == c-1){
                        res = min(res, 3);
                    }
                    if((i == 0 || i == r-1) && (j == 0 || j == c-1)){
                        res = min(res, 2);
                    }
                }
            }
        }
        if(cnt == 0){
            cout << "MORTAL\n";
        } else if(cnt == r*c){
            cout << "0\n";
        } else{
            cout << res << "\n";
        }
        F0R(i, r) rc[i] = 0;
        F0R(j, c) cc[j] = 0;
        cnt = 0;
        res = 4;
    }
    //check if 0 or bad
    //check if 1 (full edge)
    //check if 2 (corner or full mid-line)
    //check if 3 (edge thing???)
    //it's four

    return 0;
}