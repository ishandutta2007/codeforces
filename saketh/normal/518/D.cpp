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

int N, T;
double P;

double dp[2048][2048];

int main(){
    setup();
    cin >> N >> P >> T;

    for(int t=1; t<=T; t++){
        for(int n=1; n<=N; n++){
            dp[t][n] = P * (1 + dp[t-1][n-1])
                     + (1 - P) * (dp[t-1][n]);
        }
    }

    cout << dp[T][N] << endl;
}