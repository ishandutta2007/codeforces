#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cassert>
#include <sstream>
#include <set>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 2000005;



bool f[N];
int main() {
    int x = 0 , y = 0;
    f[1] = 1;
    for (int i = 2 ; i * i < N ; ++ i)
        if (!f[i]) {
            for (int j = i * i ; j < N ; j += i)
                f[j] = 1; 
        }
    int p , q;
    scanf("%d%d" , &p , &q);
    int res = -1;
    for (int i = 1 ; i < N ; ++ i) {
        x += !f[i];
        char s[20];
        char t[20];
        sprintf(s , "%d" , i);
        int len = strlen(s);
        int flag = 1;
        for (int j = 0 ; j < len / 2 ; ++ j)
            if (s[j] != s[len - j - 1])
                flag = 0;
        y += flag;
        if (x * q <= y * p)
            res = i;
    }
    if (res == -1)
        puts("Palindromic tree is better than splay tree");
    else
        cout << res << endl;
    return 0;
}