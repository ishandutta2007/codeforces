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

const int MAXN = 100005;

int N, M, K, op;
int apps[MAXN];
int loc[MAXN];

int main(){
    setup();
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> apps[i];
        loc[apps[i]] = i;
    }

    ll ans = 0;
    for(int i=0; i<M; i++){
        cin >> op;
        ans += loc[op]/K + 1;

        if(loc[op] != 0){
            int prv = apps[loc[op]-1];
            swap(apps[loc[op]], apps[loc[op]-1]);
            swap(loc[op], loc[prv]);
        } 
    }   

    cout << ans << endl; 
}