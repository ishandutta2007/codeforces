#include<stdio.h>
#include<string>
#include<set>

using namespace std;

char s[10001];
int n,m;
set<string> M;

int main(){
	scanf("%d%d",&n,&m);
	int c=0;
	for(int i=0;i<n;++i){
		scanf("%s",s);
		M.insert(s);
	}
	for(int i=0;i<m;++i){
		scanf("%s",s);
		c+=M.count(s);
	}
	n-=c,m-=c;
	n+=(c+1)/2,m+=c/2;
	printf("%s\n",n>m?"YES":"NO");
	return 0;
}