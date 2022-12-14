#include <bits/stdc++.h>
using namespace std;
const int N=255;
int a[N];
int main (){
	int n,k,m,t,l;scanf ("%d%d%d%d",&n,&k,&m,&t);
	l=n;for (int i=1;i<=n;i++) a[i]=i;int p=k;
	while (t--){
		int opt,x,s;scanf ("%d%d",&opt,&x);
		if (opt){
			for (int i=l;i>=x;i--)
				a[i+1]=a[i];
			a[x]=++n,++l;
			if (x<=p) p++;
		}else{
			if (x<p){
				for (int i=x+1;i<=l;i++) a[i-x]=a[i];
				l-=x,p-=x;
			}else{
				for (int i=x+1;i<=l;i++) a[i]=0;
				l=x;
			}
		}
		printf ("%d %d\n",l,p);
	}
	return 0;
}