#include <cstdio>
#define Maxn 11

int n , m , t , a[Maxn];
bool f[Maxn] , flag;

int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	for(int i = 1 ; i <= m ; i++){
		scanf("%d" , &t);
		f[t] = true;
	}
	for(int i = 1 ; i <= n ; i++){
		if(f[a[i]])
			if(flag)
				printf(" %d" , a[i]);
			else
				printf("%d" , a[i]) , flag = true;
	}
	printf("\n");
	return 0;
}

// By Sooke.
// CF994A Fingerprints.