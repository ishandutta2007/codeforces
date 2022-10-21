#include <bits/stdc++.h>
using namespace std;

bool prime[40005];
vector<int> P;
int p,y;

bool check(int k){
    for(int i = 0; i < P.size(); i++){
        if(P[i] > p) return true;
        if(k % P[i] == 0) return false;
    }
    return true;
}

int main() {
    fill(prime, prime+40005, true);
    for(int i = 2; i <= 31623; i++){
        if(prime[i]){
            for(int j = 2 * i; j <= 31623; j += i) prime[j] = 0;
        }
    }
    for(int i = 2; i <= 31623; i++){
        if(prime[i]) P.push_back(i);
    }
    cin >> p >> y;
    while(true){
        if(y == p) return !printf("-1");
        if(check(y)) return !printf("%d", y);
        y--;
    }

    return 0;
}