#include <cstdio>
using namespace std;

int n, x;

int main(){
    scanf("%d %d", &n, &x);
    bool f = true;
    for(int i = 0; i < n; i++){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a == x || a + x == 7 || b == x || b + x == 7){
	    f = false;
	    break;
	}
    }
    if(f) printf("YES\n");
    else printf("NO\n");
    return 0;
}