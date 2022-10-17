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

const int MAXN = 4040;

int N;
int vals[MAXN];
vector<int> all;
int dp[MAXN][MAXN];

int main(){
    setup();
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> vals[i];
        all.push_back(vals[i]);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for(int i=0; i<N; i++)
        vals[i] = lower_bound(all.begin(), all.end(), vals[i]) - all.begin();    

    int mri[MAXN];
    memset(mri, 0xff, sizeof(mri));

    int ans = 0;
    for(int i=N-1; i>=0; i--){
        for(int ov = 0; ov<all.size(); ov++){
            dp[i][ov] = 1;            
            if(mri[ov] != -1) dp[i][ov] += dp[mri[ov]][vals[i]];
            ans = max(ans, dp[i][ov]);
        }
        mri[vals[i]] = i;
    }

    cout << ans << endl;
}