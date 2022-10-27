#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=100+10;
typedef long long LL;
int n,m;
char s[N][N], t[N][N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%s",t[i]);
    }
    int q; scanf("%d",&q);
    while(q--){
        int y; scanf("%d",&y); --y;
        printf("%s%s\n", s[y%n],t[y%m]);
    }
}