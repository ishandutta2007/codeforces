#include<stdio.h>
#include<algorithm>
using namespace std;

int W;
int c[305];

int main(){
    scanf("%d", &W);
    for(int w=0; w<W; w++)
        scanf("%d", &c[w]);
    
    for(int w=0; w<W; w++){
        if(w < W-1){
            for(int i=0; i<c[w]; i++){
                printf("PRL");
            }
            printf("R");
        }
        else{
            for(int i=0; i<c[w]; i++){
                printf("PLR");
            }
        }
    }
    
    printf("\n");
        
    return 0;
}