#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100050

void work() {
    int n , x;
    int l = -1 << 30 , r = 1 << 30;
    string str , Y;
    cin >> n;
    while (n --) {
        cin >> str >> x >> Y;
        if (str == "<") {
            if (Y == "Y")
                r = min(x - 1 , r);
            else
                l = max(x , l);
        }
        if (str == "<=") {
            if (Y == "Y")
                r = min(x , r);
            else
                l = max(x + 1 , l);
        }
        if (str == ">") {
            if (Y == "Y")
                l = max(x + 1 , l);
            else
                r = min(x , r);
        }
        if (str == ">=") {
            if (Y == "Y")
                l = max(x , l);
            else
                r = min(x - 1 , r);
        }
    }
    if (l > r) {
        puts("Impossible");
    } else {
        cout << l << endl;
    }

}

int main(){
    work();
    return 0;
}