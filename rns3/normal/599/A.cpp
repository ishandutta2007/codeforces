#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main() {
    ///freopen("1.in","r",stdin);
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    int a = min(x,y+z);
    int b = min(x+y,z);
    int c = min(x+z,y);
    printf("%d\n",a+b+c);
}