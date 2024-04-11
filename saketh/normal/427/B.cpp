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

int N, T, C, A, S;

int main(){
    setup();
    cin >> N >> T >> C;

    int len = 0;
    for(int i=0; i<N; i++){
        cin >> S;
        if(S <= T){
            len++;
            if(len >= C) A++;
        }
        else len = 0;
    }

    cout << A << endl;
}