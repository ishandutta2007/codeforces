#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 1005;

char str[][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n;
char s[10];

void work() {
    scanf("%d%s" , &n , s);
    for (int i = 0 , j ; i < 8 ; ++ i) {
        if (strlen(str[i]) != n)
            continue;
        for (j = 0 ; j < n ; ++ j)
            if (s[j] != '.' && s[j] != str[i][j])
                break;
        if (j < n) continue;
        puts(str[i]); break;
    }
}

int main(){
    work();
    return 0;
}