#include <bits/stdc++.h>

using namespace std;

int n , m , f , p , pp , a[300000] , id , st;

char s[300000];

int main() {
    scanf("%d%d%s" , &n , &m , s + 1);
    f = 0; id = -1 , st = n;
    for (int i = n ; i ; i --){
    	a[i] = s[i] == '.' ? -1 : s[i] - 48;
		if (s[i] == '.') id = i;
		if (a[i] >= 5 && id == -1) st = i;
	} 
	id --;
    for (int i = st  ; i ; i --) {
        if (a[i] == -1) continue;
        p = 1 , pp = 2;
        if (s[i - 1] == '.') p ++ , pp ++;
        if (s[i - 2] == '.') pp ++;
        if (f) {
            f = 0;
            a[i] ++;
        }
        if (a[i] < 5) continue;
        if (i <= id)  {
        	if (a[i] > 9 && i != 1) a[i - 1] += 1 , a[i] -= 10;
        	continue;
		}
		if (m) {
			m --;
	        a[i] = -2;
	        a[i - p] += 1;
	        if (a[i - p] > 9 && i - pp > 0) a[i - p] -= 10 , a[i -pp] += 1;	
		}
    }
    if (a[id + 2] == -2) n = id;
    for (int i = 1 ; i <= n ; i ++) {
        if (a[i] == -2) break;
        if (a[i] == -1) {
        	printf(".");
        	continue;
		}
        printf("%d" ,a[i]);
    }
    return 0;
}