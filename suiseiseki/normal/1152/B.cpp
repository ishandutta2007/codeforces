#include <cstdio>
int x, ans[107], len;
bool check(int x) {
    x++;
    return (x & -x) == x;
}
int main() {
    scanf("%d", &x);
    int h = 28, step = 0;
    while (!(x >> h)) h--;
    while (!check(x)) {
        step++;
        if (step & 1) {
            for (int i = h; i >= 0; i--) {
                if (!((x>>i)&1)){
                    x^=((1<<(i + 1)) - 1);
                    ans[++len] = i + 1;
                    break;
                }
            }
        } else x++;
    }
    printf("%d\n",step);
    for(int i=1;i<=len;i++){
    	printf("%d ",ans[i]);
	}
	puts("");
    return 0;
}