#include <cstdio>
#include <iostream>
using namespace std;

int t, a, b, c, x, y;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
        int d = max(x - a, 0);
        ;
        puts(c >= max(x - a, 0) + max(y - b, 0) ? "YES" : "NO");
    }
	return 0;
}