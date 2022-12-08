#include<iostream>
#include<cstdio>
using namespace std;

int n,m,a[35][35],b[35];

inline void f(int &x){
	if(!x) x=-1;
}

inline int get(int x,int y,int l,int r){
	int res=0;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int p=0;p<2;p+=2){
			int q=p^x,w=p^b[i],s=w^y;
			f(p);f(q);f(w);f(s);
			tmp=max(tmp,a[i][l]*p+a[i][r]*w+a[i+n+1][l]*q+a[i+n+1][r]*s);
		}
		res+=tmp;
	}
	return res;
}

int main(){
	scanf("%d",&m);n=m/2;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
//	printf("%d\n",n);
	int ans=0;
	for(int c=0;c<2;c++){
		b[n+1]=c;
		for(int i=0;i<(1<<n);i++){
			int res=a[n+1][n+1];
			if(c) res-=res<<1;
			for(int j=1;j<=n;j++)
				if(i&(1<<j-1)) b[j]=1,res-=a[j][n+1]; else b[j]=0,res+=a[j][n+1];
			for(int j=n+2;j<=m;j++)
				if(c^b[j-n-1]) res-=a[j][n+1]; else res+=a[j][n+1];
			for(int j=1;j<=n;j++)
				res+=max(get(0,c,j,j+n+1)+a[n+1][j]+(c?-a[n+1][j+n+1]:a[n+1][j+n+1]),
				get(1,c^1,j,j+n+1)-a[n+1][j]+(c?a[n+1][j+n+1]:-a[n+1][j+n+1]));
			ans=max(ans,res);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
5
-2 0 0 0 -2
0 -2 0 -2 0
0 0 -2 0 0
0 -2 0 -2 0
-2 0 0 0 -2
*/