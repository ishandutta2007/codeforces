#include <bits/stdc++.h>

const int max_N = 1e5 + 21;

int n,a[max_N];

bool vis[max_N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		vis[a[i]]^=1;
	}
	for(int i=1;i<=n;++i)
		if(vis[a[i]]){
			puts("Conan");
			return 0;
		}
	puts("Agasa");
	return 0;
}