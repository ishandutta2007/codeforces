#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int f[] = {2 , 7 , 2 , 3 , 3 , 4 , 2 , 5 , 1 , 2};

void work() {
    int x , y;
    scanf("%1d%1d" , &x , &y);
    cout << f[x] * f[y] << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}