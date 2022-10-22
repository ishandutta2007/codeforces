#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int n; cin >> n;
    vec x(n), y(n), a(n), b(n);
    REP(i, n) cin >> x[i] >> y[i];
    set<Pii> s;
    REP(i, n){
        cin >> a[i] >> b[i];
        s.insert(Pii(a[i], b[i]));
    }
    int Tx, Ty;
    REP(i, n){
        Tx = x[0] + a[i];
        Ty = y[0] + b[i];
        bool f = true;
        REP(j, n){
            if(s.count(Pii(Tx - x[j], Ty - y[j])) == 0){
                f = false;
                break;
            }
        }
        if(f){
            cout << Tx << " " << Ty << endl;
            return 0;
        }
    }

    
    return 0;
}