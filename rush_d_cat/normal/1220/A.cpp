#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int n;
char s[N];
int main() {
    scanf("%d%s",&n,s+1);
    int x=0,y=0;
    for(int i=1;s[i];i++){
        if(s[i] == 'n') x++;
        if(s[i] == 'r') y++;
    }
    for(int i=1;i<=x;i++) printf("1 ");
    for(int i=1;i<=y;i++) printf("0 ");

}