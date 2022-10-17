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

int N;

int main(){
    setup();
    cin >> N;
   
    int ans = 0; 
    vector<int> pf;

    for(int i=0; i<N; i++){
        int val;
        cin >> val;

        while(pf.size() && pf.back() < val){
            ans = max(ans, pf.back() ^ val);
            pf.pop_back();
        }

        if(pf.size()) ans = max(ans, pf.back() ^ val);

        pf.push_back(val);
    }

    cout << ans << endl;
}