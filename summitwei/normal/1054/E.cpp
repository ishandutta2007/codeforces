#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 305
int n, m;
string s[MN][MN];
string t[MN][MN];
queue<int> st[MN][MN];
queue<int> nd[MN][MN];
vector<pair<pii, pii> > p1;
vector<pair<pii, pii> > p2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> s[i][j];
        RFOR(k, s[i][j].length()-1, 0){
            st[i][j].push(s[i][j][k]-'0');
        }
    }
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> t[i][j];
        F0R(k, t[i][j].length()){
            nd[i][j].push(t[i][j][k]-'0');
        }
    }

    FOR(i, 2, n){
        while(!st[i][1].empty()){
            int top = st[i][1].front(); st[i][1].pop();
            p1.pb({{i, 1}, {1, 1}});
            st[1][1].push(top);
        }
    }
    FOR(j, 2, m){
        while(!st[1][j].empty()){
            int top = st[1][j].front(); st[1][j].pop();
            p1.pb({{1, j}, {1, 1}});
            st[1][1].push(top);
        }
    }
    //[2, 1] = 0s. [1, 2] = 1s
    FOR(i, 2, n){
        FOR(j, 2, m){
            while(!st[i][j].empty()){
                int top = st[i][j].front(); st[i][j].pop();
                if(top == 0){
                    p1.pb({{i, j}, {i, 1}});
                    if(i != 2) p1.pb({{i, 1}, {2, 1}});
                } else{
                    p1.pb({{i, j}, {1, j}});
                    if(j != 2) p1.pb({{1, j}, {1, 2}});
                }
            }
        }
    }
    while(!st[1][1].empty()){
        int top = st[1][1].front(); st[1][1].pop();
        if(top == 0) p1.pb({{1, 1}, {2, 1}});
        else p1.pb({{1, 1}, {1, 2}});
    }


    FOR(i, 2, n){
        while(!nd[i][1].empty()){
            int top = nd[i][1].front(); nd[i][1].pop();
            p2.pb({{i, 1}, {1, 1}});
            nd[1][1].push(top);
        }
    }
    FOR(j, 2, m){
        while(!nd[1][j].empty()){
            int top = nd[1][j].front(); nd[1][j].pop();
            p2.pb({{1, j}, {1, 1}});
            nd[1][1].push(top);
        }
    }
    //[2, 1] = 0s. [1, 2] = 1s
    FOR(i, 2, n){
        FOR(j, 2, m){
            while(!nd[i][j].empty()){
                int top = nd[i][j].front(); nd[i][j].pop();
                if(top == 0){
                    p2.pb({{i, j}, {i, 1}});
                    if(i != 2) p2.pb({{i, 1}, {2, 1}});
                } else{
                    p2.pb({{i, j}, {1, j}});
                    if(j != 2) p2.pb({{1, j}, {1, 2}});
                }
            }
        }
    }
    while(!nd[1][1].empty()){
        int top = nd[1][1].front(); nd[1][1].pop();
        if(top == 0) p2.pb({{1, 1}, {2, 1}});
        else p2.pb({{1, 1}, {1, 2}});
    }

    cout << p1.size()+p2.size() << "\n";
    for(auto u : p1){
        cout << u.f.f << " " << u.f.s << " " << u.s.f << " " << u.s.s << "\n";
    }
    reverse(p2.begin(), p2.end());
    for(auto u : p2){
        cout << u.s.f << " " << u.s.s << " " << u.f.f << " " << u.f.s << "\n";
    }
    
    return 0;
}