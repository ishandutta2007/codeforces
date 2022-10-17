#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

ll N, T;

ll ncr[50][50];

int main(){
    setup();
    
    ncr[0][0] = 1;
    for(int n=1; n<50; n++)
        for(int r=0; r<=n; r++){
            ncr[n][r] = ncr[n-1][r];
            if(r) ncr[n][r] += ncr[n-1][r-1];
        }


    cin >> N >> T;

    if(__builtin_popcountll(T) != 1){
        cout << 0 << endl;
        return 0;
    }

    T = __builtin_ctzll(T) + 1;

    vector<int> digs;
    N += 2;
    ll MM = N;
    while(N){
        digs.push_back(N&1);
        N /= 2;
    }

    reverse(digs.begin(), digs.end());

    ll ans = 0;
    if(T == 1) ans--;

    for(int i=0; i<digs.size(); i++){
        if(!digs[i]) continue;
        if(int(digs.size())-1-i >= 0){
            ans += ncr[digs.size()-1-i][T];
        }       
        T--;
        if(T<0) break;
    }

    cout << ans << endl;
}