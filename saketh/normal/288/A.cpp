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

int N, K;

int main(){
    setup();
    cin >> N >> K;

    if(K > N){ cout << -1 << endl; return 0; }
    if(K == 1){
        if(N == 1) cout << "a" << endl;
        else cout << -1 << endl;
        return 0;
    }

    // we know 2 <= K <= N
    
    char g = 'a' + K - 1;
    char res[N+1];

    int j = N;
    for(; g>'b';)
        res[j--] = g--;

    for(int i=1; i<=j; i+=2)
        res[i] = 'a';

    for(int i=2; i<=j; i+=2)
        res[i] = 'b';

    for(int i=1; i<=N; i++)
        cout << res[i];
    cout << endl;
}