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

const int MAXN = 1000005; 

int N, M;
int loc[MAXN];

ll lc[MAXN], rc[MAXN];

int main(){
    setup();
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> loc[i];

    ll C = 0, L = 0;
    for(int i=0; i<N; i++){
        if(i) {
            lc[i] = (loc[i]-loc[i-1]) * C;
            lc[i] += lc[i-1];
        }
        if(L == 0) C++;
        L = (L + 1) % M;
    }

    C = 0, L = 0;
    for(int i=N-1; i>=0; i--){
        if(i<N-1){
            rc[i] = (loc[i+1]-loc[i]) * C;
            rc[i] += rc[i+1];
        }
        if(L == 0) C++;
        L = (L + 1) % M;
    }

    ll minc = 1e17;
    for(int i=0; i<N; i++)
        minc = min(minc, 2 * (lc[i] + rc[i]));
    cout << minc << endl;
}