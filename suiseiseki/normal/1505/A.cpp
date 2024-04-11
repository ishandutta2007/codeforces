#include <cstdio>
const int Maxn=1000;
int main(){
	char c=getchar();
	while(c!=EOF){
		if(c=='?'){
			puts("NO");
			fflush(stdout);
		}
		c=getchar();
	}
	return 0;
}