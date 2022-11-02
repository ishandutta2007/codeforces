#include<stdio.h>
#include<string.h>
#define M 1000001

char s[M];
int f[100];

int main(){
	//freopen("in.txt","r",stdin);
	int l,a,b,c,i,max,h,min;
	while(scanf("%s\n",s)!=EOF){
		l=strlen(s);
		f[s[l-1]]=-1;f['R'+'L'-s[l-1]]=1;
		a=0;i=0;b=0;c=0;max=0;min=M;
		while(i<l){
			for(;i<l;i++){
				if(f[s[i]]==1)break;
				b--;
			}
			if(i<l && c-b>max){max=c-b;h=c;}
			if(i<l && b<min)min=b;
			for(;i<l;i++){
				if(f[s[i]]==-1)break;
				b++;
			}
			if(b>c)c=b;
		}
		if(min>b)puts("1");
		else{
			if(c-b<=max)puts("0");
			else if(min+c-b<0)puts("0");
			else printf("%d\n",c-b+min);
		}
	}
	return 0;
}