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

int N, W;
int pots[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(20);
       
    cin >> N >> W;
    for(int i=0; i<2*N; i++){
        cin >> pots[i];
    }
    sort(pots, pots+2*N);
    
    double CL = min((double) pots[0], pots[N]/2.0);
    CL = min(CL, W / (3.0*N)); 
    cout << CL * 3 * N << endl;
}