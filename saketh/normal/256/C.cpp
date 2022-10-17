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

vector<int> locs[10];

int smm(int i, int j){
    for(int v=0; v<10; v++){
        auto it = lower_bound(locs[v].begin(), locs[v].end(), i);
        if(it == locs[v].end() || *it > j) return v;
    }
    assert(false);
}

int ci(ll v){
    ll i = floor(sqrt(v));
    while((i+1)*(i+1) <= v) i++;
    if(i == v) i--;
    return i;
}

int cj(ll v){
    ll j = ceil(sqrt(sqrt(v)));
    while((j-1)*(j-1)*(j-1)*(j-1) >= v) j--;
    return j;
}

ll N, V;
int nimb[1000000];

int main(){
    setup();

    for(int v=0; v<1e6; v++){
        nimb[v] = smm(cj(v), ci(v));
        locs[nimb[v]].push_back(v);
    }

    int res = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V;
        res ^= smm(cj(V), ci(V));
    }
    cout << (res ? "Furlo" : "Rublo") << endl;
}