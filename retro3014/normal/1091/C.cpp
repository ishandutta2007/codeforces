#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int N;
vector<ll> ans;

long long sum(ll x){
    return x*(x+1)/2;
}

void calc(int x){
    ans.push_back((N/x) + (ll)x*sum(N/x-1));
}


int main(){
    scanf("%d", &N);
    for(int i=1; i*i<=N; i++){
        if(N%i==0){
            if(i*i==N){
                calc(i);
            }else{
                calc(i); calc(N/i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        printf("%lld ", ans[i]);
    }
    return 0;
}