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

#define MN 2005
int t;
int n, k;
string s;

vpii ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> k >> s;
        --k;
        F0R(i, n){
            char c;
            if(i/2 < k){
                c = i%2?')':'(';
            } else{
                if(i == 2*k || i == n-1){
                    c = i%2?')':'(';
                } else{
                    c = i%2?'(':')';
                }
            }
            //cout << "char needed is " << c << "\n";
            if(s[i] == c) continue;
            FOR(j, i+1, n-1){
                if(s[j] == c){
                    ans.pb({i, j});
                    int l=i, r=j;
                    while(l < r){
                        swap(s[l], s[r]);
                        l++;
                        r--;
                    }
                    //cout << s << "\n";
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto u : ans){
            cout << u.f+1 << " " << u.s+1 << "\n";
        }
        ans.clear();
    }
    
    return 0;
}