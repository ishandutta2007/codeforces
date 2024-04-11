#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> S;
ll n,k;

int main(){
    cin >> n >> k;
    if(k >= 100) return !printf("No");
    for(int i = 1; i <= k; i++){
        if(!S.empty() && S.count(n % i) > 0) return !printf("No");
        S.insert(n % i);
    }
    return !printf("Yes");
}