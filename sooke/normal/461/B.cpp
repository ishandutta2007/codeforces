#include <cstdio>
#define M(n) ((n) % 1000000007)

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
	int l , fs[100001] , s[100001] , nx[300001] , v[300001];
	inline void Init(int d){
		for(int i = 1 ; i <= d ; i++)
			fs[i] = -1;
		l = 0;
	} 
	inline void Insert(int du , int dv){
		nx[l] = fs[du] , v[l] = dv;
		fs[du] = l++;
		s[du]++;
	}
};

List L;
int n , t , col[100001];
long long fx[100001] , fy[100001];

void Dfs(int d , int r){
	fx[d] = col[d] , fy[d] = 1 - col[d];
	for(int i = L.fs[d] ; i != -1 ; i = L.nx[i])
		if(L.v[i] != r)
			Dfs(L.v[i] , d),
			fx[d] = M(fy[d] * fx[L.v[i]] + fx[d] * (fx[L.v[i]] + fy[L.v[i]])),
			fy[d] = M(fy[d] * (fx[L.v[i]] + fy[L.v[i]]));
}

int main(){
	n = Read();
	L.Init(n);
	for(int i = 2 ; i <= n ; i++)
		t = Read(),
		L.Insert(t + 1 , i),
		L.Insert(i , t + 1);
	for(int i = 1 ; i <= n ; i++)
		col[i] = Read();
	Dfs(1 , 0);
	printf("%lld\n" , fx[1]);
	return 0;
}