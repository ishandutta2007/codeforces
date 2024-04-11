#include <bits/stdc++.h>

const int max_N = 5000 + 21;

int n,a[max_N],siz[max_N];

int ans[max_N],ansi;

int main(){
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			++siz[a[j]];
			if(siz[a[j]]>siz[ansi]||(siz[a[j]]==siz[ansi]&&a[j]<ansi))
				ansi=a[j];
			++ans[ansi];
		}
		for(int j=i;j<=n;++j)--siz[a[j]];
	}
	for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}