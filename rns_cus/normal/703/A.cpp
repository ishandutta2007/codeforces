#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, aa, bb;
    scanf("%d", &n);
    a = b = 0;
    while(n --){
        scanf("%d %d", &aa, &bb);
        if(aa > bb) a ++;
        else if(aa < bb) b ++;
    }
    if(a > b) puts("Mishka");
    else if(a < b) puts("Chris");
    else puts("Friendship is magic!^^");
}