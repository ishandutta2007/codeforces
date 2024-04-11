#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 105;

void work() {
    int n , m;
    cin >> n >> m;
    if (min(n , m) & 1)
        puts("Akshat");
    else
        puts("Malvika");
}

int main(){
    //freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d",&n))
        work();
    return 0;
}