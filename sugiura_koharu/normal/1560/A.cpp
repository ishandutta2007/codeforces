#include <bits/stdc++.h>

using namespace std;
int main() {    
    int T;
    scanf("%d",&T);
    while (T--) {
        int k;
        cin>>k;
        int n=1; 
        while (1) {
            if (n%3!=0 && n%10!=3) k--;
            if (k==0) {
                printf("%d\n",n);
                break ; 
            }
            n++; 
        }
    }
    return 0; 
}