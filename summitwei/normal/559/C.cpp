#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_PER 200005
#define MAX_N 2005

ll facts[MAX_PER];
ll invs[MAX_PER];

void compFacts(){
    facts[0] = 1;
    for(int i=1; i<MAX_PER; i++){
        facts[i] = facts[i-1]*i;
        facts[i] %= MOD;
        //cout << i << " factorial is " << facts[i] << "\n";
    }
}

ll factorial(ll x){
    /*ll ans = 1;
    for(ll i=1; i<=x; i++){
        ans = (ans*i)%MOD;
    }

    return ans;*/
    return facts[x];
}

pair<ll, ll> euclid(ll a, ll b){ //finds {x, y} s.t. ax+by=gcd(a, b);
    if(b == 0){
        return {1, 0};
    }

    pair<ll, ll> ans = euclid(b, a%b);
    ll x = ans.first, y = ans.second;
    return {y, x-y*(a/b)};
}

ll modInv(ll num){
    pair<ll, ll> bez = euclid(num, MOD);
    
    if(bez.first < 0) bez.first += MOD;

    return bez.first;
}

void compInvs(){
    invs[0] = 1;
    for(int i=1; i<MAX_PER; i++){
        //if(invs[i] != 0) continue;

        ll inv = modInv(facts[i]);
        invs[i] = inv;
    }
}

ll choose(ll x, ll y){
    //cout << "doing " << x << " c " << y << "\n";
    ll top = factorial(x);
    //ll bot1 = factorial(y);
    //ll bot2 = factorial(x-y);
    //ll bot = (bot1*bot2) % MOD;
    ll botInv = (invs[y]*invs[x-y])%MOD;
    //cout << "inverse of " << y << " factorial is " << invs[y] << " and x-y is " << invs[x-y] << "\n";

    //cout << x << " choose " << y << " is " << (top*botInv)%MOD << "\n";
    return (top * botInv) % MOD;
}

int h, w, n;
pii squares[MAX_N];
ll amtThru[MAX_N]; //stores the # of ways to get to the ith one

ll numWays(int ind){
    if(amtThru[ind] != -1){
        return amtThru[ind];
    }

    int x = squares[ind].first, y=squares[ind].second;
    ll total = choose(x+y-2, x-1);

    for(int i=0; i<n; i++){
        if(ind == i) continue;

        if(x >= squares[i].first && y >= squares[i].second){
            ll amtLost = (choose(x+y-squares[i].first-squares[i].second, x-squares[i].first) * numWays(i)) % MOD;
            total -= amtLost;
            if(total < 0) total += MOD;
        }
    }

    amtThru[ind] = total;
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(amtThru, -1, sizeof amtThru);

    cin >> h >> w >> n;
    for(int i=0; i<n; i++){
        cin >> squares[i].first >> squares[i].second;
    }

    compFacts();
    //cout << "hi\n";
    compInvs();
    //cout << "hi\n";

    ll total = choose(h+w-2, h-1);

    for(int i=0; i<n; i++){
        ll amtLost = (choose(h+w-squares[i].first-squares[i].second, h-squares[i].first)*numWays(i)) % MOD;
        total -= amtLost;
        if(total < 0) total += MOD;
    }

    cout << total << "\n";

    /*for(int i=0; i<n; i++){
        cout << amtThru[i] << " ";
    }*/
    
    return 0;
}