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

int N, P;
int siz[64];

int main(){
    setup();

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> siz[i];
    cin >> P;

    double ans = 0;
    double prob[51][51][51];

    for(int i=0; i<N; i++){
        memset(prob, 0, sizeof(prob));        
        prob[0][0][0] = 1; 

        int lv = 0;
        for(int j=0; j<N; j++){
            if(j == i) continue;
            for(int r=0; r<=lv; r++){
                for(int b=0; b<=P; b++){
                    double cf = (r + 1.0) / (lv + 2.0);
                    double cb = 1 - cf;
                    prob[lv+1][r][b] += prob[lv][r][b] * cb;
                    prob[lv+1][r+1][min(b+siz[j], 50)] += prob[lv][r][b] * cf;
                }
            }        
            lv++;
        }

        for(int b=0; b+siz[i]<=P; b++)
            for(int r=0; r<N; r++)
                ans += prob[lv][r][b];
    }    

    cout << ans << endl;
}