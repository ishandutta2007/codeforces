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

double P1, P2, PW;
double X, Y, R;

int main(){
    setup();
    cin >> P1 >> P2 >> PW;
    cin >> X >> Y >> R;
    PW -= R;

    double TG = P1 + R;
    Y = 2 * PW - Y; 
   
    double BVM = sqrt(pow(X, 2) + pow(Y-TG, 2));
    double DP = (P2 - TG) * (Y - TG) / BVM;    
    double MD = sqrt(pow(P2-TG, 2) - pow(DP, 2));
    
    if(MD > R - 1e-7) {
        cout << (PW-TG)/(Y-TG) * X << endl;
    }
    else cout << -1 << endl;
}