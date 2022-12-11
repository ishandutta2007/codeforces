#include<bits/stdc++.h>

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

const int N = 20;

int n;
bool f[N][400];

int main(){
	n=get();
	f[0][0]=1;
	fo(i,1,n){
		int r=get();
		fo(d,0,359){
			f[i][(d+r)%360]|=f[i-1][d];
			f[i][(d+360-r)%360]|=f[i-1][d];
		}
	}
	if (f[n][0])printf("YES\n");
	else printf("NO\n");
	return 0;
}