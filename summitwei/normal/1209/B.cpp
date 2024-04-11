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
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
int a[MN], b[MN], st[MN];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int mx = 0;
    int cur = 0;

    cin >> n;
    cin >> s;
    F0R(i, n){
        cin >> a[i] >> b[i];
        if(s[i] == '1'){
            st[i] = 1;
            ++cur;
        }
    }
    mx = cur;
    FOR(i, 1, 150){
        F0R(j, n){
            if(i % a[j] == b[j] % a[j] && i >= b[j]){
                if(st[j]){
                    st[j] = 0;
                    --cur;
                } else{
                    st[j] = 1;
                    ++cur;
                }
            }
        }
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    
    return 0;
}