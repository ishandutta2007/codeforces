#include <cstdio>
#include <algorithm>
using namespace std;
bool read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='\n'){
			return 0;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(c=='\n'){
		return 0;
	}
	return 1;
}
int a[105];
int main(){
	int len=0;
	while(read(a[++len]));
	sort(a+1,a+1+len);
	int last;
	for(int i=1;i<=len;i=last){
		last=i+1;
		while(last<=len&&a[last]-a[last-1]<=1){
			last++;
		}
		if(a[last-1]==a[i]){
			printf("%d",a[i]);
		}
		else{
			printf("%d-%d",a[i],a[last-1]);
		}
		if(last<=len){
			putchar(',');
		}
	}
	puts("");
	return 0;
}