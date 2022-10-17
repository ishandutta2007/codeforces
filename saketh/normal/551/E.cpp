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
    cout.tie(0);
}

typedef long long ll;

int N, Q, B, T, L, R, X;
ll val[500005];
ll grp[500005];
vector<vector<pair<ll, int> > > nums;

void remake(int buck){
    nums[buck].resize(B);
    for(int i=0; i<B; i++)
        nums[buck][i] = make_pair(val[buck*B+i], buck*B+i);
    sort(nums[buck].begin(), nums[buck].end());
}

int main(){
    setup();
    cin >> N >> Q;

    B = round(sqrt(N));
    T = (N + B - 1) / B;
    nums.resize(T);

    for(int i=0; i<N; i++)
        cin >> val[i];
    
    for(int i=0; i<T; i++)
        remake(i);

    for(int i=0; i<Q; i++){
        int QT; cin >> QT;
        if(QT == 1){
            cin >> L >> R >> X;
            L--, R--;
            
            for(;L<=R && L%B; L++)
                val[L] += X;
            if(L) remake((L-1)/B);
            
            while(L/B < R/B){
                grp[L/B] += X;                
                L+=B;
            }
            
            for(;L<=R; L++)
                val[L] += X;
            if(L) remake((L-1)/B);
        }
        else{
            int Y;
            cin >> Y;

            int f = -1, l = -1;            
            for(int g=0; g<T; g++){
                ll look = Y - grp[g]; 

                if(f == -1){
                    auto it = lower_bound(nums[g].begin(), nums[g].end(), make_pair(look, -1));
                    if(it!=nums[g].end() && it->first == look){
                        f = it->second;
                        l = it->second;
                    }
                }

                auto it2 = upper_bound(nums[g].begin(), nums[g].end(), make_pair(look, 0x7f7f7f7f));
                if(it2 != nums[g].begin()){
                    --it2;
                    if(it2->first == look) l = it2->second;
                }
            }

            if(f == -1) cout << f << "\n";
            else cout << l-f << "\n";
        }
    }
}