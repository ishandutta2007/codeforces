#include<cstdio>
#include<cstring>
using namespace std;

char st[100100];
int con[100100],a[100100];
int main(){
	int n;scanf("%s",st);
	int l=strlen(st);
	if(st[0]!='('){
		printf("-1\n");
		return 0;
	}
	n=0;for(int i=0;i<l;i++)if(st[i]=='#')n++;
	con[0]=1;
	int cnt=0,lst;
	for(int i=1;i<l;i++){
		if(st[i]=='(')con[i]=con[i-1]+1;
		if(st[i]==')')con[i]=con[i-1]-1;
		if(st[i]=='#')cnt++;
		if(st[i]=='#' && cnt<n)con[i]=con[i-1]-1;
		if(st[i]=='#' && cnt==n)lst=i,con[i]=con[i-1];
	}
	int ans=con[l-1];
	if(ans<=0){
		printf("-1\n");
		return 0;
	}
	for(int i=lst;i<l;i++)con[i]-=ans;
	for(int i=0;i<l;i++)
		if(con[i]<0){
			printf("-1\n");
			return 0;
		}
	for(int i=0;i<n-1;i++)printf("1\n");
	printf("%d\n",ans);
	return 0;
}