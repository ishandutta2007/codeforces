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

const int N = 305;

int n;
int d[N];
int m;
struct edge{
	int x,y;
	edge(const int x_=0,const int y_=0){x=x_;y=y_;}
}e[1000005];

int main(){
	n=get();
	fo(i,1,n)d[i]=get();
	int he=1,ta=n;
	while(he<=ta){
		if (he==ta){
			fo(x,1,d[ta]+1)
				fo(y,x+1,d[ta]+1)e[++m]=edge(x,y);
			ta--;
		}
		else{
			int now=d[ta]+1,u=d[he];
			fo(tim,1,u){
				fo(i,1,now-1)e[++m]=edge(now,i);
				fo(i,he,ta-1)d[i]--;
				now--;
			}
			he++,ta--;
		}
	}
	printf("%d\n",m);
	fo(i,1,m)printf("%d %d\n",e[i].x,e[i].y);
	return 0;
}