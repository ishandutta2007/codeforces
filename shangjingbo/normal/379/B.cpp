#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double PI = acos(-1.0);

int n, a[1000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        //a[i] = 300;
    }
    
    int pos = 0;
    string answer = "";
    while (true) {
        int next = -1;
        for (int i = 0; i < n; ++ i) {
            if (a[i]) {
                next = i;
                break;
            }
        }
        if (next == -1) {
            break;
        }
        while (pos < next) {
            answer += "R";
            ++ pos;
        }
        while (pos > next) {
            answer += "L";
            -- pos;
        }
        
        while (a[next] > 0) {
            if (pos - 1 >= 0) {
                answer += "LRP";
            } else {
                answer += "RLP";
            }
            -- a[next];
        }
    }
    //printf("%d\n", answer.size());
    printf("%s\n", answer.c_str());
    
    return 0;
}