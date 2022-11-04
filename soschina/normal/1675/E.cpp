#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 2;

int t, n, k;
char s[N], to[256];

int main(){
	scanf("%d", &t);
    while(t--){
        for (char c = 'a'; c <= 'z'; c++)
            to[c] = c;
        scanf("%d%d%s", &n, &k, s + 1);
        for (int i = 1; i <= n; i++){
            while(s[i] != to[s[i]])
                s[i] = to[s[i]];
            while(s[i] > 'a' && k > 0){
                to[s[i]] = s[i] - 1;
                s[i] = to[s[i]];
                while(s[i] != to[s[i]])
                    s[i] = to[s[i]];
                k--;
            }
        }
        printf("%s\n", s + 1);
    }
	return 0;
}