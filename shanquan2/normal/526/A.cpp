#include<cstdio>
using namespace std;

bool a[1000]={0};
char st[200];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",st);
	for(int i=0;i<n;i++)if(st[i]=='*')a[i]=1;else a[i]=0;
	bool f=0;
	for(int d=1;d<n;d++)
		for(int i=0;i<n;i++)
			if(a[i] && a[i+d] && a[i+2*d] && a[i+3*d] && a[i+4*d])f=1;
	if(f)printf("yes\n");else printf("no\n");
	return 0;
}