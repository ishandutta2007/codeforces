#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int n;
int a[100010], b[100010];
int x[100010], y[100010];
multiset <int> s;
int query(int x){
    int ans = (1<<29);
    __typeof(s.begin()) itr = s.lower_bound(x);
    if(itr != s.end()){
        int y = (*itr);
        ans = min(ans, y - x);
    }
    if(itr != s.begin()){
        itr--;
        int y = (*itr);
        ans = min(ans,x - y);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        a[i]--;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d",&b[i]);
        b[i]--;
    }
    for(int i = 0; i < n; ++i) x[a[i]] = i;
    for(int i = 0; i < n; ++i) y[b[i]] = i;
    for(int i = 0; i < n; ++i)
        s.insert(x[i] - y[i]);
    for(int i = 0; i < n; ++i){
        int ans = query(-i);
        printf("%d\n", ans);
        int tmp = x[b[i]] - y[b[i]];
        s.erase(s.find(tmp));
        s.insert(tmp - n);
    }
    return 0;
}