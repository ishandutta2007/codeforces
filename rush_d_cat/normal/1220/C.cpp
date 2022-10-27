#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 500000 + 10;
char s[N];

int main() {
    scanf("%s", s+1);
    int mn = 10000;
    for(int i=1;s[i];i++) {
        if(mn >= s[i])
            printf("Mike\n");
        else
            printf("Ann\n");
        mn = min(mn, (int)s[i]);
    }
}