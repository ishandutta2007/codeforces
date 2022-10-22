#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
char str[5050];

bool isPal(int k){
    for (int i=1; i<=k; i++) if (str[i] != str[k-i+1]) return false;
    return true;
}

int main(){
    scanf("%s", str+1);
    N = strlen(str+1);
    bool tf = true;
    for (int i=1; i<N/2; i++) if (str[i] != str[i+1]) tf = false;
    if (tf){
        puts("Impossible");
        return 0;
    }
    while (1){
        if (N&1){
            puts("2");
            return 0;
        }
        if (isPal(N/2)) N /= 2;
        else{
            puts("1");
            return 0;
        }
    }
    return 0;
}