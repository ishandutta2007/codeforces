#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5;

ll x, k;
int cur = 0;
vector<ll> dv;
vector<ll> num;
vector<int> dvs[N];

void add(ll x){
    printf("%I64d ", x);
    if(++cur == N) exit(0);
}

void dfs(int i, int lev){
    if(i == 0 || lev == k){
        add(num[i]);
        return;
    }
    for(auto x : dvs[i]){
        dfs(x, lev + 1);
    }
}


int main(){
    scanf("%I64d%I64d", &x, &k);
    ll cur;
    for(cur = 1; cur * cur < x; cur++){
        if(x % cur == 0){
            num.push_back(cur);
            num.push_back(x / cur);
        }
    }
    if(cur * cur == x) num.push_back(cur);
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size(); i++){
        for(int j = 0; j < num.size(); j++){
            if(num[i] % num[j] == 0) dvs[i].push_back(j);
        }
    }
    if(k == 0) return !printf("%I64d\n", x);
    dfs(num.size()-1, 0);

}