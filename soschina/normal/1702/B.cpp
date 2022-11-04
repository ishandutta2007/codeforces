#include <cstdio>
using namespace std;
const int N = 2e5 + 2;

int t;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s + 1);
        char ch[3] = {};
        int ans = 1;
        for (char *c = s + 1; *c; c++){
            bool flag = false;
            for (int i = 0; i < 3; i++){
                if(!ch[i]){
                    ch[i] = *c;
                    flag = true;
                    break;
                }
                else if(ch[i] == *c){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans++;
                ch[0] = *c;
                ch[1] = 0;
                ch[2] = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}