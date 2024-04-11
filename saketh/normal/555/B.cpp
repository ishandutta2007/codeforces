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

typedef long long ll;
const int MAXN = 200005;

int N, M;
pair<ll, ll> isl[MAXN];
ll bri[MAXN];
int bord[MAXN];

pair<ll, ll> rng[MAXN]; // all ranges
int ord_s[MAXN];
int ord_e[MAXN];

set<pair<ll, int> > all;  // available ranges sorted by endpoint
int res[MAXN];

int main(){
    setup();
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> isl[i].first >> isl[i].second;
        if(i){
            ll lo = isl[i].first - isl[i-1].second;            
            ll hi = isl[i].second - isl[i-1].first;
            rng[i-1] = {lo, hi};
            ord_s[i-1] = i-1;
            ord_e[i-1] = i-1;    
        }
    }

    N--;
    sort(ord_s, ord_s+N, [](int i, int j){ return rng[i].first < rng[j].first; });
    sort(ord_e, ord_e+N, [](int i, int j){ return rng[i].second < rng[j].second; });

    for(int i=0; i<M; i++){
        cin >> bri[i];
        bord[i] = i;
    }

    sort(bord, bord+M, [](int i, int j){ return bri[i] < bri[j]; });

    int a = 0;
    int b = 0;
    int MM = 0;

    for(int i=0; i<M; i++){
        ll blen = bri[bord[i]];

        // insert everything that starts before this        
        while(a < N && rng[ord_s[a]].first <= blen){
            all.insert({rng[ord_s[a]].second, ord_s[a]});
            a++;
        }

        // pop everything that ended
        while(b < N && rng[ord_e[b]].second < blen){
            all.erase({rng[ord_e[b]].second, ord_e[b]});
            b++;
        }

        // try to match
        if(!all.size()) continue;
        res[all.begin()->second] = bord[i] + 1;
        all.erase(all.begin());
        MM++;
    }

    if(MM != N){ cout << "No\n"; return 0; }

    cout << "Yes\n";
    for(int i=0; i<N; i++)
        cout << res[i] << " ";;
    cout << endl;
}