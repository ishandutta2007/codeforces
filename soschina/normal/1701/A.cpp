#include <cstdio>
using namespace std;

int t, ans, x;

int main(){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        for (int i = 0; i < 4; i++){
            scanf("%d", &x);
            ans += x;
        }
        if(!ans)
            puts("0");
        else if(ans <= 3)
            puts("1");
        else
            puts("2");
    }
    return 0;
}