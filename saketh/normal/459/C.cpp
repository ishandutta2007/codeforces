#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
// #include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <math.h>
 
using namespace std;
 
int bus(int k, int stud, int day) {
    // Write stud in base k, then get the digit in the k^day place.
    if (log2(stud) < day * log2(k) - (1e-5))
        return 0;
    return (((int)floor(stud/pow(k, day))) % k);
}
 
 
int k, n, d;
 
int main(void) {
    cin >> n >> k >> d;
    if (log2(n) > d * log2(k) + 1.0e-5)
        cout << -1;
    else {
        for (int day = 0; day < d; day++) {
            for (int stud = 0; stud < n; stud++) {
                if (stud == 0)
                    cout << 1;
                else {
                    cout << " " << 1 + bus(k, stud, day);
                }
            }
            cout << "\n";
        }
    }
}