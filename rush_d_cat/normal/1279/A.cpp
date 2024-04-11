#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
    scanf("%d", &t);
    while (t --) {
        int a[3];
        for(int i=0;i<3;i++) scanf("%d",&a[i]);
        sort(a,a+3);
        if(a[0]+a[1]+1 >= a[2]) printf("Yes\n");
        else printf("No\n");
    }
}


/*
ababa
*/