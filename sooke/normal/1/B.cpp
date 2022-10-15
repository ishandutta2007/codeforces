#include <cstdio>
#include <cstring>
#define IsNumber(c) ((c) >= '0' && (c) <= '9')
#define IsLetter(c) ((c) >= 'A' && (c) <= 'Z')

int n , l , m , f , a , b;
char c[101] , s[101];

int main(){
    for(scanf("%d" , &n) ; n ; n--){
        scanf("%s" , c);
        l = strlen(c) - 1;
        a = b = m = 0;
        for(int i = 1 ; i <= l ; i++)
            if(IsLetter(c[i - 1]) && IsNumber(c[i]))
                m++ , f = i - 1;
        if(m < 2){
            for(int i = 0 ; i <= f ; i++)
                a = (a << 1) + (a << 3) + (a << 4) + (c[i] - 64);
            for(int i = f + 1 ; i <= l ; i++)
                b = (b << 1) + (b << 3) + (c[i] ^ 48);
            printf("R%dC%d\n" , b , a);
            continue;
        }
        for(int i = 1 ; i <= f - 1 ; i++)
            a = (a << 1) + (a << 3) + (c[i] ^ 48);
        for(int i = f + 1 ; i <= l ; i++)
            b = (b << 1) + (b << 3) + (c[i] ^ 48);
        for(l = 1 ; b ; l++)
            if(b % 26 == 0)
                s[l] = 'Z' , b /= 26 , b--;
            else
                s[l] = b % 26 - 1 + 'A' , b /= 26;
        for(l-- ; l ; l--)
            printf("%c" , s[l]);
        printf("%d\n" , a);
    }
    return 0;
}