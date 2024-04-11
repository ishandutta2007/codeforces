#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	static int a[1005][1005];
	for(int i=0,st=0;i<n;i+=4)
		for(int j=0;j<n;j+=4,st+=16)
			for(int x=0;x<4;++x)
				for(int y=0;y<4;++y)
					a[i+x][j+y]=st+4*x+y;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			printf("%d%c",a[i][j]," \n"[j+1==n]);
	return 0;
}