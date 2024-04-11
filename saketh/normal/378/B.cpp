#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int a[100005];
int b[100005];

int main(){
    scanf("%d", &N);
    for(int n=0; n<N; n++)
        scanf("%d %d", &a[n], &b[n]);
        
    int TA = 0, TB = 0;
    while(TA + TB < N){
        if(a[TA] < b[TB]) TA++;
        else TB++;
    }
    
    TA = max(TA, N/2);
    TB = max(TB, N/2);
    
    for(int i=0; i<N; i++)
        if(i < TA) printf("1");
        else printf("0");
    printf("\n");
    
    for(int i=0; i<N; i++)
        if(i < TB) printf("1");
        else printf("0");
    printf("\n");
    
    return 0;
}