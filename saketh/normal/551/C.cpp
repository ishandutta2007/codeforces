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

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
}

typedef long long ll;

int N, S;
ll ps[100005];

int main(){
	setup();
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> ps[i];
    while(ps[N-1] == 0) N--;

    ll ans = 1e15;
    ll lo = 1, hi = ans;

    while(lo <= hi){
        ll mi = (lo + hi) / 2;  
    
        vector<ll> avail(S, mi);
        int elap = 0;

        for(int i=0; i<N; i++){
            elap++;
            ll spend = ps[i];
            
            while(spend){
                if(avail.size() == 0) goto FAIL;
                ll off = avail.back();
                if(off <= elap){
                    avail.pop_back();
                }
                else if(off - elap > spend){
                    avail.back() -= spend;
                    spend = 0;
                }
                else{
                    spend -= off - elap;
                    avail.pop_back();
                }
            }
        }

        if(false){
            FAIL:
            lo = mi + 1;
        }
        else{
            ans = mi;
            hi = mi - 1;
        }
    }

    cout << ans << endl;
}