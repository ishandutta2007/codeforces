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

const int MOD = 1000000007;
const int BIG = 2100;

int pasc[BIG][BIG];

int K;
int col[BIG];
int dp[BIG][BIG];

int main(){
    setup();

    pasc[0][0] = 1;
    for(int n=1; n<=2000; n++)
        for(int r=0; r<=n; r++){
            pasc[n][r] = pasc[n-1][r];
            if(r) pasc[n][r] = (pasc[n][r] + pasc[n-1][r-1]) % MOD;
        }

    cin >> K;
    for(int i=0; i<K; i++)
        cin >> col[i];

    ll ans = 1;
    int balls = col[0];

    for(int i=1; i<K; i++){
        ans = (ans * pasc[balls+col[i]-1][balls]) % MOD;
        balls += col[i];
    }

    cout << ans << endl;
}