#include<stdio.h>
#include<string.h>
#include<memory.h>
#define N 150

int n, m, b[30];
char a[N][N], x, c;

int main(){
    int ans = 0;
    memset(b, 0, sizeof b);
    scanf("%d %d %c\n", &n, &m, &c);
    for(int i = 0; i < n; i ++){
        gets(a[i]);
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(a[i][j] == '.' || a[i][j] == c ) continue;
            else{
                x = a[i][j];
                if(i > 0 && a[i-1][j] == c) b[x - 'A'] = 1;
                else if( j > 0 && a[i][j-1] == c) b[x - 'A'] = 1;
                else if( i < (n-1) && a[i+1][j] == c) b[x - 'A'] = 1;
                else if( j < (m-1) && a[i][j+1] == c) b[x - 'A'] = 1;
            }
        }
    }
    for(int i = 0; i < 26; i ++ ) ans += b[i];
    printf("%d\n", ans);
}