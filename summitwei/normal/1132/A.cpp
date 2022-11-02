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

#define MN 1005
int cnt[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    if(cnt[0] != cnt[3]){
        cout << "0\n";
    } else if(cnt[0] == 0 && cnt[2] != 0){
        cout << "0\n";
    } else{
        cout << "1\n";
    }
    
    return 0;
}