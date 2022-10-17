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

int N, F, Z;

int main(){
    setup();
    cin >> N;
    for(int i=0; i<N; i++){
        int v;
        cin >> v;
        if(v) F++;
        else Z++;
    }

    while(F*5 % 9) F--;
    if(Z == 0){
        cout << -1 << endl;
        return 0;
    }

    if(F == 0) Z = 1;

    for(int i=0; i<F; i++)
        cout << 5;
    for(int i=0; i<Z; i++)
        cout << 0;
    cout << endl;
}