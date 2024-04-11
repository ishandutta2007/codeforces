#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define INF 2000000000

typedef long long ll;

ll N, M, K;

int main(){
    cin>>N>>K;
    N=min(N, K-1);
    M=K-N;
    if(M>=N){
        cout<<0;
        return 0;
    }
    cout<<(N-M+1)/2;
    return 0;
}