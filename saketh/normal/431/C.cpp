#include<iostream>
#include<vector>
#include<string.h>

#define MOD 1000000007

using namespace std;

int N, K, D;
bool seen[105][2];
long long ways[105][2];

long long calc(int sum, bool need){
    if(sum < 0) return 0;
    if(sum == 0) return !need;
    
    if( seen[sum][need] ) return ways[sum][need];
    seen[sum][need] = true;
    
    ways[sum][need] = 0;
    
    for(int edg=1; edg<=min(K, sum); edg++){
        if(edg < D && need) ways[sum][need] = (ways[sum][need] + calc(sum - edg, 1)) % MOD;
        else{
            ways[sum][need] = (ways[sum][need] + calc(sum - edg, 0)) % MOD;
        }
    }
    
    return ways[sum][need];
}

int main(){
    memset(seen, 0, sizeof(seen));

    cin >> N >> K >> D;
    cout << calc(N, 1) << endl;;
    
    return 0;
}