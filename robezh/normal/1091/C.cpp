#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> dvs;
vector<ll> res;

int main(){
    cin >> n;
    int i;
    for(i = 1; i * i < n; i++){
        if(n % i == 0){
            dvs.push_back(i);
            dvs.push_back(n/i);
        }
    }
    if(i * i == n) dvs.push_back(i);

    for(int x : dvs){
        int las = (n / x - 1) * x + 1;
        ll cur = 1LL * (n / x) * (las + 1) / 2;
        res.push_back(1LL * (n / x) * (las + 1) / 2);
    }
    sort(res.begin(), res.end());
    for(ll x : res){
        printf("%I64d ", x);
    }
}