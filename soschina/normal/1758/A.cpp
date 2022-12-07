#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101;

int t;
char s[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        printf("%s", s);
        reverse(s, s + strlen(s));
        printf("%s\n", s);
    }
	return 0;
}