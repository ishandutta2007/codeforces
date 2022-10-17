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

int M, N;
int item[100100];

int main(){
    setup();

    int BB = 1e9;
    cin >> M;
    for(int i=0; i<M; i++){
        int B;
        cin >> B;
        BB = min(BB, B);
    }

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> item[i];

    sort(item, item+N, greater<int>());

    int cost = 0;
    for(int i=0; i<N; ){
        for(int j=0; j<BB; j++){
            if(i+j == N) break;
            cost += item[i+j];
        }
        i+=BB+2;
    }

    cout << cost << endl;
}