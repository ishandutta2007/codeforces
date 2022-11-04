#include <cstdio>
#include <map>
using namespace std;

int t, n, q, u, x, y;

map<int, int> a, b;

int main(){
	scanf("%d", &t);
    while(t--){
        a.clear();
        b.clear();
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++){
            scanf("%d", &u);
            b[u] = i;
            if(!a[u])
                a[u] = i;
        }
        while(q--){
            scanf("%d%d", &x, &y);
            if(a[x] && b[y] && a[x] <= b[y])
                puts("YES");
            else
                puts("NO");
        }
    }
	return 0;
}