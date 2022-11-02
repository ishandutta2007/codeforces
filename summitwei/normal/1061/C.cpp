#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int a[MAX_N];
int n;

int cnt[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }

    RFOR(i, n-1, 0){
        FOR(j, 1, sqrt(a[i])+EPSILON){
            if(a[i] % j != 0) continue;

            cnt[j] = (cnt[j]+cnt[j+1]+1) % MOD;
            int other = a[i]/j;
            if(other <= n && j != other){
                cnt[other] = (cnt[other] + cnt[other+1] + 1) % MOD;
            }
        }
    }

    cout << cnt[1] << "\n";
    
    return 0;
}