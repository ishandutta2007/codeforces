#include <cstdio>
#define Maxn 1000005

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , cnt , a[Maxn] , pl[Maxn];

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		pl[a[i]] = i;
	}
	for(int i = 1 ; i <= n ; i++)
		if(a[i] != i){
			cnt++;
			int t = pl[i];
			a[t] = a[i];
			pl[a[i]] = t;
			a[i] = i;	
		}
	if((cnt + n) & 1)
		printf("Um_nik\n");
	else
		printf("Petr\n");
	return 0;
}

// By Sooke.
// CF986B Petr and Permutations.