#include<cstdio>
using namespace std;

int main(){
	int n,m;scanf("%d%d",&n,&m);
	char ch1[50],ch2[50];
	scanf("%s%s",ch1,ch2);
	if(ch1[0]=='<' && ch1[n-1]=='>' && ch2[0]=='v' && ch2[m-1]=='^'){
		printf("YES\n");
		return 0;
	}
	if(ch1[0]=='>' && ch1[n-1]=='<' && ch2[0]=='^' && ch2[m-1]=='v'){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}