#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 300005
int n;
vector<pair<pii, int> > gr;
vector<pair<pii, int> > ls;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        int a, b;
        cin >> a >> b;
        if(a > b) gr.pb({{a, b}, i});
        else ls.pb({{a, b}, i});
    }

    int g = gr.size();
    int l = ls.size();

    sort(gr.begin(), gr.end());
    sort(ls.begin(), ls.end(), greater<pair<pii, int> >());
    
    if(g > l){
        cout << g << "\n";
        F0R(i, g){
            cout << gr[i].s+1 << " ";
        }
    } else{
        cout << l << "\n";
        F0R(i, l){
            cout << ls[i].s+1 << "\n";
        }
    }
    

    return 0;
}