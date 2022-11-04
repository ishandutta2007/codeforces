#include <cstdio>
#include <cmath>
using namespace std;

int t, n, m, sx, sy, d;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);
        bool flag = false;
        bool subflag = true;
        for (int j = 1; j <= m; j++){
            int x = 1, y = j;
            if(abs(x - sx) + abs(y - sy) <= d)
                subflag = false;
        }
        for (int i = 1; i <= n; i++){
            int x = i, y = m;
            if(abs(x - sx) + abs(y - sy) <= d)
                subflag = false;
        }
        flag |= subflag;
        subflag = true;
        for (int j = 1; j <= m; j++){
            int x = n, y = j;
            if(abs(x - sx) + abs(y - sy) <= d)
                subflag = false;
        }
        for (int i = 1; i <= n; i++){
            int x = i, y = 1;
            if(abs(x - sx) + abs(y - sy) <= d)
                subflag = false;
        }
        flag |= subflag;
        if(!flag)
            puts("-1");
        else
            printf("%d\n", n + m - 2);
    }
    return 0;
}