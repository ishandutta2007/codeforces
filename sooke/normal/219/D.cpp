#include <cstdio>
#include <cstdlib>
#define Maxn 200001
#define Maxe 400001

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9'){
		if(c == EOF)
			exit(0);
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

struct List{
	int len , fst[Maxn] , nxt[Maxe] , v[Maxe] , w[Maxe];
	inline void Init(int d){
		for(int i = 1 ; i <= d ; i++)
			fst[i] = -1;
		len = 0;
	}
	inline void Insert(int _u , int _v , int _w){
		v[len] = _v;
		w[len] = _w;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

List L;
int n , sum , _min , ans[Maxn];

void DfsA(int u , int f){
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i] , w = L.w[i];
		if(v != f){
			DfsA(v , u);
			sum += w;
		}
	}
}
void DfsB(int u , int f , int cnt){
	ans[u] = cnt;
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i] , w = L.w[i];
		if(v != f)
			if(w == 0)
				DfsB(v , u , cnt + 1);
			else
				DfsB(v , u , cnt - 1);
	}
}

int main(){
	while(true){
		n = Read();
		sum = 0 , _min = 2147400000;
		L.Init(n);
		for(int i = 2 ; i <= n ; i++){
			int u = Read() , v = Read();
			L.Insert(u , v , 0);
			L.Insert(v , u , 1);	
		}
		DfsA(1 , 0);
		DfsB(1 , 0 , sum);
		for(int i = 1 ; i <= n ; i++)
			if(_min > ans[i])
				_min = ans[i];
		printf("%d\n" , _min);
		for(int i = 1 ; i <= n ; i++)
			if(_min == ans[i])
				printf("%d " , i);
		printf("\n");
	}
	return 0;
}

// By Sooke.
// CF219D Choosing Capital for Treeland.