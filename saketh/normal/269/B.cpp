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

const int NN = 5005;

int N, M;
int dp[NN][NN];
int vs[NN];

int main(){
    setup();
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> vs[i];
        double tmp;
        cin >> tmp;
    }

    int ans = 0;

    for(int l=0; l<N; l++){
        for(int v=0; v<=M; v++){
            dp[l+1][v] = max(dp[l+1][v], dp[l][v]);
            if(v <= vs[l]){
                dp[l+1][vs[l]] = max(dp[l+1][vs[l]],
                    1 + dp[l][v]);
                ans = max(ans, 1 + dp[l][v]);    
            }
        }
    }

    cout << N - ans << endl;
}