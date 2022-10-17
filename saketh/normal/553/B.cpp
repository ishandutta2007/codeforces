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

typedef unsigned long long ll;
const ll INF = 1e18;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

ll N, K;

ll fib[51];

int main(){
    setup();
    
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i<=50; i++){
        fib[i] = min(fib[i-1] + fib[i-2], INF);
    }   

    cin >> N >> K;
    K--;

    for(int i=0; i<N;){
        int rem = N - i - 1;
        if(K >= fib[rem]){
            K -= fib[rem];
            cout << i+2 << " " << i+1 << " ";
            i += 2;
        }
        else{
            cout << i+1 << " ";
            i++;
        }
    }

    cout << endl;
}