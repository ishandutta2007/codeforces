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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, k;
int fst[MN];
int lst[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(fst, 0x3f, sizeof fst);
    memset(lst, -1, sizeof lst);


    cin >> n >> k;
    F0R(i, k){
        int x;
        cin >> x;
        fst[x] = min(fst[x], i);
        lst[x] = i;
    }

    ll cnt = 0;

    FOR(i, 1, n){
        //cout << i;
        if(lst[i] == -1){
            cnt+=3;
            if(i == 1 || i == n) cnt--;
            //cout << "+3\n";
            continue;
        }
        if(i != 1 && lst[i-1] < fst[i]){
            cnt++;
            //cout << "+-1";
        }
        if(i != n && lst[i+1] < fst[i]){
            cnt++;
            //cout << "++1";
        }
        //cout << "\n";
    }
    cout << cnt << "\n";
    
    return 0;
}