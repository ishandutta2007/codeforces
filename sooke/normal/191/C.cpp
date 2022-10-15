// 

#include <cstdio>
#define Maxn 100001
#define Maxe 200001
#define Logn 18

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

struct List{
	int len , fst[Maxn] , nxt[Maxe] , v[Maxe];
	inline void Init(int d){
		for(int i = 1 ; i <= d ; i++)
			fst[i] = -1;
		len = 0;
	}
	inline void Insert(int _u , int _v){
		v[len] = _v;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

List L;
int n , m , dep[Maxn] , f[Logn][Maxn] , bac[Maxn] , ans[Maxn];

void DfsA(int u , int fth){
	dep[u] = dep[fth] + 1;
	f[0][u] = fth;
	for(int i = 1 ; i < Logn ; i++)
		f[i][u] = f[i - 1][f[i - 1][u]];
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(v != fth){
			bac[i / 2 + 1] = v;
			DfsA(v , u);
		}
	}
}
int DfsB(int u){
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(v != f[0][u])
			ans[u] += DfsB(v);
	}
	return ans[u];
}

inline int Lca(int u , int v){
	if(dep[u] < dep[v])
		u ^= v , v ^= u , u ^= v;
	int c = dep[u] - dep[v];
	for(int i = Logn - 1 ; i >= 0 ; i--)
		if(c >= (1 << i)){
			c -= 1 << i;
			u = f[i][u];
		}
	if(u == v)
		return u;
	for(int i = Logn - 1 ; i >= 0 ; i--)
		if(f[i][u] != f[i][v]){
			u = f[i][u];
			v = f[i][v];
		}
	return f[0][u];
}

int main(){
	n = Read();
	L.Init(n);
	for(int i = 2 ; i <= n ; i++){
		int u = Read() , v = Read();
		L.Insert(u , v);
		L.Insert(v , u);
	}
	DfsA(1 , 0);
	m = Read();
	for(int i = 1 ; i <= m ; i++){
		int u = Read() , v = Read();
		int lca = Lca(u , v);
		ans[u] += 1;
		ans[v] += 1;
		ans[lca] -= 2;
	}
	DfsB(1);
	for(int i = 1 ; i < n - 1 ; i++)
		printf("%d " , ans[bac[i]]);
	printf("%d\n" , ans[bac[n - 1]]);
	return 0;
}

// By Sooke.
// CF191C Fools and Roads.