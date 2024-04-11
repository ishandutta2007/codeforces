#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    for(int i = sqrt(n); i > 0; i --){
        if(n % i == 0){ printf("%d %d\n", i, n / i); return 0; }
    }
}