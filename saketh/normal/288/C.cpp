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

int main(){
    setup();
    int N;
    cin >> N;
    int O = N;

    vector<int> r(N+1, 0);

    while(N > 0){
        int LB = 1 << (31-__builtin_clz(N));
        int M = N;
        while((M-1)&LB) M--;
   
        int A = M-1, B = M;
        while(B <= N){
            r[A] = B;
            r[B] = A;
            A--;
            B++;
        } 

        N = A;
    }

    ll ans = 0;
    for(int i=0; i<O+1; i++)
        ans += i ^ r[i];

    cout << ans << endl;
    for(int v : r) 
        cout << v << " ";
    cout << endl;
}