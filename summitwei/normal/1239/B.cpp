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
string s;
int a[MN];
string t;
int b[MN];
 
void op(int x, int l, int r, int mnl){
    cout << x << "\n";
    cout << (l+mnl+n)%n+1 << " " << (r+mnl+n)%n+1 << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int mnl = 0;
    cin >> n >> s;
    FOR(i, 1, n){
        if(s[i-1] == '(') a[i] = a[i-1]+1;
        else a[i] = a[i-1]-1;
        if(a[i] < a[mnl]) mnl = i;
    }
    if(a[n] != 0){
        cout << "0\n1 1\n";
        return 0;
    }
 
    t = s; mnl%=n;
    F0R(i, n){
        t[i] = s[(i+mnl)%n];
    }
    //cout << t << " " << mnl << "\n";
    FOR(i, 1, n){
        if(t[i-1] == '(') b[i] = b[i-1]+1;
        else b[i] = b[i-1]-1;
    }
 
    int zc = 0;
    FOR(i, 1, n){
        if(b[i] == 0) ++zc;
    }
    
    int mx = 0; pii ans = {2, 1};
    int l=1, ct = 0;
    FOR(r, 1, n){
        if(b[r] <= 1){
            l = r+1; ct = 0;
        } else if(b[r] == 2){
            ++ct;
        }
        if(ct > mx){
            mx = ct;
            ans = {l, r};
        }
    }
 
    int mx2 = 0; pii ans2 = {2, 1};
    l=1, ct=0;
    FOR(r, 1, n){
        if(b[r] <= 0){
            l = r+1; ct = 0;
        } else if(b[r] == 1){
            ++ct;
        }
        if(ct > mx2){
            mx2 = ct;
            ans2 = {l, r};
        }
    }
    if(mx+zc >= mx2){
        op(mx+zc, ans.f-1, ans.s, mnl);
    } else{
        op(mx2, ans2.f-1, ans2.s, mnl);
    }
 
    return 0;
}