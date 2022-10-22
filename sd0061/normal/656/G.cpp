#include <cstdio>
char s[105][105];
int n , m , T , c;
int main() {
    scanf("%d%d%d",&n,&m,&T);
for (int i = 0 ; i < n ; ++ i)scanf("%s",s[i]);
for (int j = 0 ; j < m ; ++ j) {
int x = 0;
for (int i = 0 ; i < n ; ++ i)
x += (s[i][j] == 'Y');
c += x >= T;
}//kitten
printf("%d\n",c);
return 0;
}