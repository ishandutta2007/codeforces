#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;

typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	bool pd=0;
	int s=ch-'0';
	if (ch=='-'){pd=1;s=0;}
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (pd)return -s;
	else return s;
}

int sum,n,a[N];
bool bz[N];


int main(){
	n=get();
	for (int i=1;i<=n;i++){a[i]=get(); sum+=a[i];}
	for (int i=1;i<=n;i++) if (!bz[i]){
		for (int j=i+1;j<=n;j++) if (!bz[j] && a[i]+a[j]==sum/(n/2)){
			printf("%d %d\n",i,j); 
			bz[j]=1; 
			break;
		}
	}
	return 0;
}