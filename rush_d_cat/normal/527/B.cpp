#include <iostream>
using namespace std;
const int N = 200000 + 10;
int n;
char s[N],t[N];
int pos[30][30];
int main() {
    scanf("%d %s %s", &n, s+1, t+1);
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        pos[s[i]-'a'][t[i]-'a'] = i;
        if(s[i] != t[i]) cnt ++;
    }
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) if(i!=j) {
            if(pos[i][j] && pos[j][i]) {
                printf("%d\n", cnt-2);
                printf("%d %d\n", pos[i][j], pos[j][i]);
                return 0;
            }
        }
    }
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            // i,j   j,k
            for(int k=0;k<26;k++){
                if(i==j || j==k) continue;
                if(pos[i][j]&&pos[j][k]) {
                    printf("%d\n", cnt-1);
                    printf("%d %d\n", pos[i][j], pos[j][k]);
                    return 0;
                }
            }
        }
    }
    printf("%d\n", cnt);
    printf("-1 -1\n");

}