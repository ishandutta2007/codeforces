#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

#define maxn 110

using namespace std;

char s[maxn];

int main(){
        scanf("%s", s);
        bool res = false;
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
                res = res || (s[i] == 'H' || s[i] == 'Q' || s[i] == '9');
        if (res) printf("YES\n"); else printf("NO\n");
        return 0;
}