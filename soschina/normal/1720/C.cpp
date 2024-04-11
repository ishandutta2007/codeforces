#include <cstdio>
using namespace std;
const int N = 502;

int t, n, m;
char s[N][N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++)
                if(s[i][j] == '1')
                    cnt++;
        }
        if(cnt == n * m){
            printf("%d\n", cnt - 2);
            continue;
        }
        bool flag = true;
        for (int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if((s[i][j] == '0') + (s[i + 1][j] == '0') + (s[i][j + 1] == '0') + (s[i + 1][j + 1] == '0') >= 2)
                    flag = false;
        printf("%d\n", cnt - flag);
    }
	return 0;
}