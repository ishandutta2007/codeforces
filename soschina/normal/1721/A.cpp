#include <cstdio>
using namespace std;

int t;

int main(){
	scanf("%d", &t);
    while(t--){
        int n = 4, cnt = 0;
        bool vis[26] = {};
        while(n--){
            char c;
            scanf(" %c", &c);
            c -= 'a';
            if(!vis[c]){
                cnt++;
                vis[c] = true;
            }
        }
        printf("%d\n", cnt - 1);
    }
	return 0;
}