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

    int ans = 0;
    int fre = 0;

    cin >> N >> K;
    for(int i=0; i<K; i++){
        int X, Y;
        cin >> X;
        vector<int> dolls;

        for(int j=0; j<X; j++){
            cin >> Y;
            dolls.push_back(Y);
        }    

        int j = 0;
        while(j < dolls.size() && dolls[j] == j+1) j++;
        if(j == 0) j = 1;

        ans += X - j;        
        fre += X - j + 1;
    }

    ans += fre - 1;
    cout << ans << endl;
}