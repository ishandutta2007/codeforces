#include <iostream>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

const int MAXN = 1028;
const ll INF = 0x3fffffffffffffff;

int N;
set<int> all;
int H[MAXN], W[MAXN];

ll calc(int mh){
    ll width = 0;
    int can_lie = N/2;
    priority_queue<int> red;

    for(int i=0; i<N; i++){
        if(H[i] > mh && W[i] > mh) return INF;
        if(H[i] > mh){
            width += H[i];
            can_lie--;
        }
        else{
            width += W[i];
            if(W[i] <= mh && H[i] < W[i])
                red.push(W[i] - H[i]);
        }
    }

    if(can_lie < 0) return INF;
    while(!red.empty() && can_lie > 0){
        can_lie--;
        width -= red.top();
        red.pop();
    }
    return width * mh;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> W[i] >> H[i];
        all.insert(H[i]);
        all.insert(W[i]);
    }

    ll ans = INF;
    for(int mh : all)
        ans = min(ans, calc(mh));

    cout << ans << endl;
}