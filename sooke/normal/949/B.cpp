#include <cstdio>
#define lol long long

inline lol Read(){
    char c = getchar();
    long long n = 0;
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9')
        n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
    return n;
}

lol n , q;

int main(){
    n = Read() , q = Read();
    for(int i = 1 ; i <= q ; i++){
        lol t = n * 2 - Read();
        while((t & 1) == 0)
            t >>= 1;
        printf("%I64d\n" , n - (t - 1) / 2);
    }
    return 0;
}

// By Sooke.
// CF949B A Leapfrog in the Array.