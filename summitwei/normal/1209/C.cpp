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
int t;
int d[MN];
int c[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        FOR(i, 1, n){
            d[i] = s[i-1]-'0';
        }
        bool fd = false;
        F0R(i, 10){
            int a = 0;
            int b = i;
            bool ok = true;
            FOR(j, 1, n){
                if(d[j] < i){
                    if(a > d[j]){
                        ok = false;
                        continue;
                    } else{
                        a = d[j];
                        c[j] = 1;
                    }
                } else if(d[j] == i){
                    if(b == i){
                        c[j] = 2;
                    } else{
                        a = i;
                        c[j] = 1;
                    }
                } else{
                    if(b > d[j]){
                        ok = false;
                        continue;
                    } else{
                        b = d[j];
                        c[j] = 2;
                    }
                }
            }
            if(ok){
                FOR(i, 1, n){
                    cout << c[i];
                }
                cout << "\n";
                fd = true;
                break;
            }
        }
        if(!fd){
            cout << "-\n";
        }
    }
    
    return 0;
}