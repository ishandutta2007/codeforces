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

int prod(int a, int b){
    return a * 1ll * b % 1000000007;
}

int N, K;

int main(){
    setup();
    cin >> N >> K;

    int MM = 1;
    for(int i=1; i<K; i++)
        MM *= K;

    int ans = 0;

    for(int m=0; m<MM; m++){
        int sign[K];
        for(int t=m, i=1; i<K; i++, t/=K)
            sign[i] = t%K;

        vector<bool> rch(K);
        rch[0] = true;
        bool good = true;
        while(good){
            good = false;
            for(int i=1; i<K; i++)
                if(rch[sign[i]] && !rch[i]){
                    good = true;
                    rch[i] = true;
                }
        }

        bool all = true;
        for(bool v : rch) all &= v;
        ans += all;
    }    

    ans = prod(ans, K);
    for(int i=K; i<N; i++)
        ans = prod(ans, N-K);
    cout << ans << endl;
}