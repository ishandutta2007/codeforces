#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 1005;
int n , val[26] , K;
char s[N];

void work() {
    int i , j = 0 , res = 0;
    scanf("%s%d" , s , &K);
    for (i = 0 ; i < 26 ; ++ i)
        scanf("%d" , &val[i]) , j = max(j , val[i]);
    for (i = 0 ; s[i] ; ++ i)
        res += val[s[i] - 'a'] * (i + 1);
    n = strlen(s);
    while (K) {
        -- K , ++ n;
        res += n * j;
    }
    cout << res << endl;
}

int main()
{
    work();
    return 0;
}