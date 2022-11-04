#include <cstdio>
using namespace std;

int t, now, a[4];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &now);
        for (int i = 1; i <= 3; i++)
            scanf("%d", &a[i]);
        int cnt = 0;
        while(now){
            now = a[now];
            cnt++;
        }
        if(cnt == 3)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}