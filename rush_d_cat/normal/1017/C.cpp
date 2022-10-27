#include <iostream>
#include <cmath>
using namespace std;
int n;
int main() {
    cin >> n;

    int blk;
    int mx = 1e9;  
    for(int i=1;i<=n;i++) {
        int tmp = i + (n+i-1)/i;
        if(tmp<mx) mx=tmp, blk=i; 
    }
    int las = blk, cnt=0;
    while(true) {
        int now = las;
        for(int i=0;i<blk;i++) {
            if(now-i>=1 && now-i<=n) {
                printf("%d ", now-i);
                cnt ++;
            }
        }
        las = now + blk;
        if (cnt == n) break;
    }
}