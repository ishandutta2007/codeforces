#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int N, M;
char g[128][128];
int dp[128][128];

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
}

int main(){
	setup();
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> g[i][j];

    int ops = 0;
    for(int i=N-1; i>=0; i--)
       for(int j=M-1; j>=0; j--){
            dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            int need = g[i][j] == 'B' ? -1 : 1;
            ops += abs(need - dp[i][j])>0;
            dp[i][j] = need;
       } 
    
    cout << ops << endl;
}