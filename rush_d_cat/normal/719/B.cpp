#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define INF 1e9 + 7
typedef long long ll;
using namespace std;
#define MAXN 100000 + 10
#define MAXM 2000 + 10
char s[MAXN];
int main()
{
    int n, i, res = 0;
    cin >> n;
    scanf("%s", s+1);
    int b = 0, r = 0 ,b_ = 0, r_ = 0;
    for(i = 1; i <= n; i++)
    {
        if(i%2 == 1)
        {
            if(s[i] == 'b') {r++;}
            if(s[i] == 'r') {b_++;}
        } else {
            if(s[i] == 'r') {b++;}
            if(s[i] == 'b') {r_++;}
        }
    }
    res = min(max(b, r), max(b_,r_));
    cout << res << endl;
}