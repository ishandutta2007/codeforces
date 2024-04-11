#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int time;
    time=240-k;
    int i=1;
    while(time>=5*i){
        time=time-5*i;
        i++;
    }
    i--;
    if(n<i)
        printf("%d\n",n);
    else
        printf("%d\n",i);
    
    return 0;
}