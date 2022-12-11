#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 110;
const int INF = 1e+9;

int n,f[N][3];

int main(){
	scanf("%d",&n);
	f[0][0]=f[0][1]=INF;
	fo(i,1,n){
		int x;
		scanf("%d",&x);
		f[i][0]=f[i][1]=f[i][2]=INF;
		f[i][2]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
		switch(x){
		case 0:break;
		case 1:
			f[i][1]=min(f[i-1][0],f[i-1][2]);
			break;
		case 2:
			f[i][0]=min(f[i-1][1],f[i-1][2]);
			break;
		case 3:
			f[i][1]=min(f[i-1][0],f[i-1][2]);
			f[i][0]=min(f[i-1][1],f[i-1][2]);
			break;
		}
	}
	printf("%d\n",min(min(f[n][0],f[n][1]),f[n][2]));
	return 0;
}