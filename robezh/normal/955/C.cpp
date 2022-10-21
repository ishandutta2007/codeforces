#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> S;
vector<ll> nums;

ll root(ll k){
    ll l = -1, r = (ll)1e9 + 1, mid;
    while(l+1 < r){
        mid = (l+r) / 2;
        ll sqr = mid * mid;
        if(sqr == k) return mid;
        else if(sqr < k) l = mid;
        else r = mid;
    }
    return l;
}

void pre(){
    auto U = (ll)1e18;
    for(ll i = 2; i <= 1e6; i++){
        for(ll cur = i * i * i; cur <= U; cur *= i){
            S.insert(cur);
            if(cur > U / i) break;
        }
    }
    //cout << S.size();
    for(ll s : S){
        ll r = root(s);
        if(r * r == s) continue;
        nums.push_back(s);
    }
}


int main(){
    pre();
    //cout << "DOne";
    ll l, r;
    int q;
    //for(int i = 0; i < 10; i++) cout << nums[i] << " ";
    scanf("%d", &q);
    while(q--){
        scanf("%I64d%I64d", &l, &r);
        ll res = upper_bound(nums.begin(), nums.end(), r) - upper_bound(nums.begin(), nums.end(), l-1);
        //printf("%I64d ", res);
        res += root(r) - root(l-1);
        printf("%I64d\n", res);
    }
}