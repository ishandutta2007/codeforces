#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;

int n,x1,x2;
int c[N];
int num[N];

bool cmp(int x,int y){return c[x]<c[y];}

int main(){
	n=get();x1=get();x2=get();
	fo(i,1,n)c[num[i]=i]=get();
	sort(num+1,num+1+n,cmp);
	
	bool ans=0;
	int lst=0;
	fd(i,n,1){
		int lim=(x1-1)/c[num[i]]+1;
		if (lim<=n-i+1){lst=i;break;}
	}
	if (lst){
		fd(i,lst-1,1){
			int lim=(x2-1)/c[num[i]]+1;
			if (i+lim-1<lst){
				printf("Yes\n%d %d\n",n-lst+1,lst-i);
				fo(x,lst,n)printf("%d ",num[x]);putchar('\n');
				fo(x,i,lst-1)printf("%d ",num[x]);putchar('\n');
				return 0;
			}
		}
	}
	lst=0;
	fd(i,n,1){
		int lim=(x2-1)/c[num[i]]+1;
		if (lim<=n-i+1){lst=i;break;}
	}
	if (lst){
		fd(i,lst-1,1){
			int lim=(x1-1)/c[num[i]]+1;
			if (i+lim-1<lst){
				printf("Yes\n%d %d\n",lst-i,n-lst+1);
				fo(x,i,lst-1)printf("%d ",num[x]);putchar('\n');
				fo(x,lst,n)printf("%d ",num[x]);putchar('\n');
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}