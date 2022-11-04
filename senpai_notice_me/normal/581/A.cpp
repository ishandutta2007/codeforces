#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,c,d;

int main() {
    scanf("%d%d",&a,&b);
    c=min(a,b);
    d=(max(a,b)-min(a,b))/2;
    printf("%d %d",c,d);
    
    return 0;
}