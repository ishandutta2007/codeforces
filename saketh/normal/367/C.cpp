#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, Q, W, H, A;
vector<ll> cost;

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> Q >> W;
        cost.push_back(W);
    }

    for(int t=1; t<=M; t++){
        ll e = (t*(t-1LL))/2;
        if(!(t%2)) e += t/2-1;
        if(e < N) H = t;
    }

    sort(cost.begin(), cost.end(), greater<ll>());
    for(int i=0; i<H; i++) A += cost[i];
    cout << A << endl;
    return 0;
}