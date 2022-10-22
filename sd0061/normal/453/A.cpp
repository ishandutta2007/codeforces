#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 100005;
int n , m;
void work() {
    double res = 0;
    scanf("%d%d",&m,&n);
    double LG = log(m);
    for (int i = 1 ; i <= m ; ++ i) {
        res += exp(log(i) * (n + 1) - n * LG);
        if (i > 1) {
            res -= exp(log(i - 1) * n + log(i) - n * LG);
        }
    }
    printf("%.10f\n" , res);
}

int main(){
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}