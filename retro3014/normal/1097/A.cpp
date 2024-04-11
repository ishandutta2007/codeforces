#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char c[6][2];
char t;
bool tf=false;

int main(){
    for(int i=0; i<6; i++){
        scanf("%c%c", &c[i][0], &c[i][1]);
        scanf("%c", &t);
        if(i!=0){
            if(c[0][0]==c[i][0] || c[0][1]==c[i][1]){
                tf=true;
            }
        }
    }
    if(tf){
        printf("YES");
    }else{
        printf("NO");
    }
}