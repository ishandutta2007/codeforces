#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000009
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, k;
string s;
int len[27];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> s;

    if(k == 1){
        int mx = 0;
        F0R(i, n){
            len[s[i]-'a']++;
            mx = max(mx, len[s[i]-'a']);
        }
        cout << mx << "\n";
        return 0;
    }

    int st = 1;
    //int lv = 0;

    FOR(i, 1, n-1){
        if(s[i] == s[i-1]){
            st++;
            //cout << "one on " << i << "\n";
            if(st == k){
                //cout << "done on " << i << "\n";
                st = 0;
                len[s[i]-'a']++;
            }
        } else{
            st = 1;
        }
    }

    int mx = 0;
    F0R(i, 26){
        mx = max(mx, len[i]);
    }

    cout << mx << "\n";

    return 0;
}