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

map<int,int> H;
int main(){
    int n=get(),l=get(),x=get(),y=get();
    if(x>y)swap(x,y);
    int flag1=0,flag2=0,flag3=0;
    fo(i,1,n){
        int k=get();
        H[k]=1;
        if(H[x])flag1=1;
        if(H[k-x])flag1=1;
        if(H[k+x])flag1=1;
        if(H[k-y])flag2=1;
        if(H[k+y])flag2=1;
        if(H[y])flag2=1;
        if(H[k-x-y])flag3=k-x;
        if(H[k-(y-x)]){
            if(k+x<=l)flag3=k+x;
            else if(k-y>=0)flag3=k-y;
        }
    }
    if(flag1&&flag2)printf("0\n");
    else if(flag1)printf("1\n%d\n",y);
    else if(flag2)printf("1\n%d\n",x);
    else if(flag3)printf("1\n%d\n",flag3);
    else printf("2\n%d %d\n",x,y);
}