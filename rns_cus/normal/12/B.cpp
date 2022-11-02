// B
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, m, res, len, pos;
int a[20];
char s[100];

int main(){
    scanf("%d\n", &n);
    gets(s);
    len =  strlen(s);
    if((len > 1 and s[0] == '0') or len > 11) puts("WRONG_ANSWER");
    else{
        m = 0;
        for(int i = 0; i < len; i ++) m = m * 10 + (s[i] - '0');
        res = pos = 0;
        while(n){
            a[pos ++] = n % 10;
            n /= 10;
        }
        sort(a, a + pos);
        for(int i = 0; i < pos; i ++) if(a[i]) { swap(a[0], a[i]); break; }
        for(int i = 0; i < pos; i ++) res = res * 10 + a[i];
        if( m == res) puts("OK");
        else puts("WRONG_ANSWER");
    }
}