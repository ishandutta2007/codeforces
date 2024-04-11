#include <cstdio>
#include <cstring>
#include <algorithm>
#define Maxn 1000005

using namespace std;

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
    int len , fst[Maxn] , nxt[Maxn << 1] , v[Maxn << 1];
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

struct Val{
	int n , i; 
};

bool Cmp(Val x , Val y){
	return x.n < y.n;
}

List L;
Val S[Maxn];
int n , siz[Maxn] , f[Maxn];
long long sum , cnt , ans;
bool used[Maxn];

inline void Init(){
	memset(used , false , sizeof(used));
	for(int i = 1 ; i <= n ; i++){
		siz[i] = 1;
		f[i] = i;
	}
}

int Find(int d){
	return f[d] == d ? d : f[d] = Find(f[d]);
}
inline int Merge(int x , int y){
	x = Find(x) , y = Find(y);
	siz[x] += siz[y];
	f[y] = x;
}

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		S[i].n = Read();
		S[i].i = i;
	}
	L.Init(n);
	for(int i = 2 ; i <= n ; i++){
		int u = Read() , v = Read();
		L.Insert(u , v);
		L.Insert(v , u);
	}
	sort(S + 1 , S + n + 1 , Cmp);
	Init();
	for(int i = 1 ; i <= n ; i++){
		int u = S[i].i;
		sum = 2;
		cnt = 0;
		used[u] = true;
		for(int j = L.fst[u] ; j != -1 ; j = L.nxt[j]){
			int v = L.v[j];
			if(used[v])
				sum += siz[Find(v)];
		}
		for(int j = L.fst[u] ; j != -1 ; j = L.nxt[j]){
			int v = L.v[j];
			if(used[v]){
				cnt += (sum - siz[Find(v)]) * siz[Find(v)];
				Merge(u , v);
			}
		}
		ans += cnt * S[i].n;
	}
	Init();
	for(int i = n ; i >= 1 ; i--){
		int u = S[i].i;
		sum = 2;
		cnt = 0;
		used[u] = true;
		for(int j = L.fst[u] ; j != -1 ; j = L.nxt[j]){
			int v = L.v[j];
			if(used[v])
				sum += siz[Find(v)];
		}
		for(int j = L.fst[u] ; j != -1 ; j = L.nxt[j]){
			int v = L.v[j];
			if(used[v]){
				cnt += (sum - siz[Find(v)]) * siz[Find(v)];
				Merge(u , v);
			}
		}
		ans -= cnt * S[i].n;
	}
	printf("%lld\n" , ans >> 1);
	return 0;
}

// By Sooke.
// CF915F Imbalance Value of a Tree.