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

int query(int x){
	printf("? %d\n",x);fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}

int main(){
	int n;
	scanf("%d",&n);
	if ((n/2)&1){
		printf("! -1\n");fflush(stdout);
		return 0;
	}
	if (n<=10){
		fo(i,1,n/2){
			int x=query(i),y=query(i+n/2);
			if (x==y){
				printf("! %d\n",i);fflush(stdout);
				return 0;
			}
		}
		printf("! -1\n");fflush(stdout);
		return 0;
	}
	int x=query(1),y=query(1+n/2);
	if (x==y){
		printf("! %d\n",1);fflush(stdout);
		return 0;
	}
	int l=1,r=n/2;
	if (x>y){
		while(l<=r){
			int mid=(l+r)/2;
			int delt=query(mid)-query(mid+n/2);
			if (delt==0){
				printf("! %d\n",mid);fflush(stdout);
				return 0;
			}
			if (delt>0)l=mid+1;
			else r=mid-1;
		}
	}
	else{
		while(l<=r){
			int mid=(l+r)/2;
			int delt=query(mid)-query(mid+n/2);
			if (delt==0){
				printf("! %d\n",mid);fflush(stdout);
				return 0;
			}
			if (delt>0)r=mid-1;
			else l=mid+1;
		}
	}
	printf("! -1\n");fflush(stdout);
	return 0;
}