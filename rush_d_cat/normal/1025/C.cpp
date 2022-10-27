#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
char s[N]; int n;
int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i=n+1;i<=2*n;i++) {
        s[i] = s[i-n];
    }

    int mx=1,now=1;
    for(int i=2;i<=2*n;i++) {
        if(s[i]!=s[i-1]) {
            now ++; mx = max(mx, now);
        } else {
            now = 1;
        }
    }
    mx = min(mx, n);
    cout << mx << endl;
}