#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100100;

int P[MAXN];
int R[MAXN];
int S[MAXN];

void init(int N){
    for(int i=0; i<N; i++){
        P[i] = i;
        R[i] = 0;
        S[i] = 1;
    }
}

int rep(int i){
    if(P[i] != i) P[i] = rep(P[i]);
    return P[i];
}

bool unio(int a, int b){
    a = rep(a);
    b = rep(b);
    if(a == b) return false;
    if(R[a] < R[b]){
        P[a] = b;
        S[b] += S[a];
    }
    else{
        P[b] = a;
        S[a] += S[b];
    }
    if(R[a] == R[b]) R[a]++;
    return true;
}

int N, K;
vector<ll> v;
vector<bool> u;

int idx(ll x){
    auto it = lower_bound(v.begin(), v.end(), x);
    if(it!=v.end() && *it == x) return it - v.begin();
    return -1;
}

int main(){
    setup();

    cin >> N >> K;
    v.resize(N);
    for(ll &x : v) cin >> x;
    sort(v.begin(), v.end());

    init(N);

    for(int i=0; i<N; i++){
        if(v[i] % K == 0){
            int i1 = idx(v[i] / K);
            if(i1 != -1) unio(i1, i);
        }
        int i2 = idx(v[i] * K);
        if(i2 != -1) unio(i2, i);
    }   
    
    u.resize(N);
    int ans = 0;

    for(int i=0; i<N; i++){
        if(u[rep(i)]) continue;
        u[rep(i)] = true;
        ans += (S[rep(i)]+1)/2;
    }

    cout << ans << endl;
}