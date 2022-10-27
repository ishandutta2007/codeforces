#include <iostream>
using namespace std;
typedef long long LL;
const int N=100000+10;

int n,q;
int f[3][N];
int main() {
    scanf("%d%d",&n,&q);
    int bu=0;
    for(int i=1;i<=q;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        if(f[r][c]==1 && f[3-r][c]==1) bu--;
        if(c>=2 && f[r][c]==1 && f[3-r][c-1]==1) bu--;
        if(c< n && f[r][c]==1 && f[3-r][c+1]==1) bu--;        
        f[r][c]^=1;
        if(f[r][c]==1 && f[3-r][c]==1) bu++;
        if(c>=2 && f[r][c]==1 && f[3-r][c-1]==1) bu++;
        if(c< n && f[r][c]==1 && f[3-r][c+1]==1) bu++;
        printf("%s\n", bu>=1?"No":"Yes");
    }
}