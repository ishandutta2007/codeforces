#include <stdio.h>
#include <algorithm>
using namespace std;
char s[110];
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d",&n);
		scanf("%s", s);
		bool ans = true;
		for(int i = 0; i < n; i++)
			if(!(s[i]-s[n-i-1]==2||s[i]-s[n-i-1]==0||s[i]-s[n-i-1]==-2))
				ans = false;
		printf("%s\n", ans?"YES":"NO");
	}
	return 0;
}