#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            printf("? %d %d\n", l, mid);
            fflush(stdout);
            int cnt = 0;
            for (int x, i = l; i <= mid; i++){
                scanf("%d", &x);
                if(x >= l && x <= mid)
                    cnt++;
            }
            if(cnt & 1)
                r = mid;
            else
                l = mid + 1;
        }
        printf("! %d\n", l);
        fflush(stdout);
    }
	return 0;
}