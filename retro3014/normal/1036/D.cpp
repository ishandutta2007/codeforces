#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int N, M;
ll t;
vector<ll> A, B;

ll a, b;
int idx=0;
int ans=0;

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%lld", &t);
        A.push_back(t);
    }
    scanf("%d", &M);
    for(int i=1; i<=M; i++){
        scanf("%lld", &t);
        B.push_back(t);
    }
    for(int i=0; i<N; i++){
        a+=A[i];
        while(b<a && idx<M){
            b+=B[idx];
            idx++;
        }
        if(a==b){
            ans++;
            a=0;
            b=0;
        }
    }
    if(a!=b || idx!=M){
        printf("-1");
        return 0;
    }
    printf("%d", ans);
    return 0;
}