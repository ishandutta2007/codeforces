#include <stdio.h>
#include <stdlib.h>
using namespace std;

int i;

int main()
{
    for(i=0;i<=8;++i)printf("%d??<>%d\n",i,i+1);
    printf("9??>>??0\n");
    printf("??0<>10\n");
    for(i=0;i<=9;++i)printf("?%d>>%d?\n",i,i);
    printf("?>>??\n");
    printf(">>?\n");
}