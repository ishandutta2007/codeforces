#include <cstdio>
#define Maxn 100001
#define Maxe 200001
#define Max(x , y) ((x) > (y) ? (x) : (y))

inline int Read(){
    char c = getchar();
    int n = 0 , f = 0;
    while(c < '0' || c > '9'){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
        n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
    return f ? -n : n;
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
int n;
long long val[Maxn] , add[Maxn] , dec[Maxn];

void Dfs(int u , int f){
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(v != f){
			Dfs(v , u);
			add[u] = Max(add[u] , add[v]);
			dec[u] = Max(dec[u] , dec[v]);
		}
	}
	val[u] -= dec[u];
	val[u] += add[u];
	if(val[u] > 0)
		dec[u] += val[u];
	else
		add[u] -= val[u];
}

int main(){
    n = Read();
    L.Init(n);
    for(int i = 2 ; i <= n ; i++){
        int u = Read() , v = Read();
        L.Insert(u , v);
        L.Insert(v , u);
    }
    for(int i = 1 ; i <= n ; i++){
        val[i] = Read();
    	if(val[i] > 0)
    		dec[i] += val[i];
    	else
    		add[i] -= val[i];
	}
    Dfs(1 , 0);
    printf("%lld\n" , add[1] + dec[1]);
    return 0;
}

// By Sooke.
// CF274B Zero Tree.