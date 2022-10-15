#include <cstdio>
#define Maxn 1001

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , m , t , v , ans , w[Maxn] , stc[Maxn] , pls[Maxn];

int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++)
		w[i] = Read();
	for(int i = 1 ; i <= m ; i++){
		t = Read();
		if(pls[t] == 0)
			pls[t] = ++v;
		for(int i = pls[t] ; i >= 2 ; i--){
			pls[stc[i - 1]] = i;
			stc[i] = stc[i - 1];
			ans += w[stc[i]];
		}
		stc[1] = t;
		pls[t] = 1;
	}
	printf("%d\n" , ans);
	return 0;
}

// By Sooke.
// CF500C New Year Book Reading.