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
 
#define MN 305
int n;
string s;
int ree[MN];
int query(string t){
    cout << t << endl;
    cout.flush();
    int res;
    cin >> res;
    if(res == -1) exit(0);
    if(res == 0) exit(0);
    return res;
}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    int n = query("a")+1;
    if(n == 301){
        F0R(_, 300) cout << "b";
        cout << endl;
        return 0;
    }
    s.resize(n);
    F0R(i, n) s[i] = 'a';
    int amt = query(s);
    if(amt == n){
        s.resize(n-1);
        F0R(i, n-1) s[i] = 'b';
        query(s);
        return 0;
    }
    int cnt = 0;
    F0R(i, n-1){
        s[i] = 'b';
        int cur = query(s);
        if(cur < amt){
            ree[i] = 1;
            ++cnt;
        }
        s[i] = 'a';
    }
    if(cnt != amt){
        ree[n-1] = 1;
    }
    F0R(i, n){
        if(ree[i]) s[i] = 'b';
    }
    query(s);
    
    return 0;
}