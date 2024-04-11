#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,k,x;
int main(){
    while(~scanf("%I64d",&n)){
        if (n%3){
            while (n%3) n++;
            n/=3;
            printf("%I64d\n",n);
            continue;
        }else{
            if (n%9){
                n+=3;
                if (n%9) n+=3;
                k=9;
            }else{
                k=9;
                while(n%k==0) k*=3;
            }
            n=(n-1)/k+1;
            printf("%I64d\n",n);
        }
    }
    return 0;
}