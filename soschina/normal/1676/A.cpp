#include <cstdio>
using namespace std;
const int N = 7;

int t;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        puts(s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES" : "NO");
    }
    return 0;
}