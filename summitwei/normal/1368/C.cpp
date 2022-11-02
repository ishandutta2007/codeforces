#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n;
vpii gr;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    FOR(i, 1, n){
        int x=3*i, y=0;
        F0R(d, 5){
            int cx = x+dx[d], cy = y+dy[d];
            gr.pb({cx, cy});
        }
        if(i%2 == 0){
            gr.pb({3*i, 2});
            gr.pb({3*i-1, 2});
            gr.pb({3*i-2, 2});
            gr.pb({3*i-3, 2});
        } else if(i>1){
            gr.pb({3*i, -2});
            gr.pb({3*i-1, -2});
            gr.pb({3*i-2, -2});
            gr.pb({3*i-3, -2});
        }
    }
    gr.pb({1, 0});
    gr.pb({1, -1});
    gr.pb({1, -2});
    gr.pb({2, -2});
    gr.pb({3, -2});
    if(n%2 == 0){
        gr.pb({3*n+2, 0});
        gr.pb({3*n+2, -1});
        gr.pb({3*n+2, -2});
        gr.pb({3*n+1, -2});
        gr.pb({3*n, -2});
    } else{
        gr.pb({3*n+2, 0});
        gr.pb({3*n+2, 1});
        gr.pb({3*n+2, 2});
        gr.pb({3*n+1, 2});
        gr.pb({3*n, 2});
    }

    cout << gr.size() << "\n";
    for(auto u : gr) cout << u.f << " " << u.s << "\n";

    return 0;
}