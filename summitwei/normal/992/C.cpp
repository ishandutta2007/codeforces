#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
typedef vector<vector<set<int>>> vvsi;
typedef vector<vector<set<pair<long long, long long>>>> vvspll;
typedef pair<long long, long long> pll;
typedef pair<long long, pair<long long, long long>> trip;
#define INF 100000000
#define MOD 1000000007
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

ll power(ll base, ll expo){
    ll soFar = 1;
    ll currBase = base;
    while(expo > 0){
        if(expo % 2 == 0){
            currBase = (currBase * currBase) % MOD;
            expo /= 2;
        } else{
            soFar *= currBase;
            soFar %= MOD;
            expo--;
        }
    }
    
    return soFar;
}

int main(){
    ll x, k;

    cin >> x >> k;
    if(x == 0){
        cout << 0;
        return 0;
    }

    x %= MOD;
    k %= (MOD-1);

    //formula: (2*x-1)*2^k+1

    ll powed = power(2, k);
    ll other = 2*x-1;

    powed %= MOD;
    other = mod(other, MOD);

    ll answer = (powed*other+1) % MOD;

    cout << answer;
    return 0;
}