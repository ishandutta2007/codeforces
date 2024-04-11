#include <cstdio>
#include <cstring>
#define Maxn 150001

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

struct Node{
	int i;
	long long k;
};
struct SmallRootHeap{
	Node V[Maxn];
	int siz;
	inline void Swap(int x , int y){
		V[0] = V[x];
		V[x] = V[y];
		V[y] = V[0];
	}
	inline void PushUp(int d){
		while(d > 1 && ((V[d].k < V[d >> 1].k) || (V[d].k == V[d >> 1].k && V[d].i < V[d >> 1].i))){
			Swap(d , d >> 1);
			d = d >> 1;
		}
	}
	inline void PushDown(int d){
		int l , r , c;
		while(true){
			l = d << 1 , r = l | 1;
			if(l > siz)
				break;
			else if(r > siz)
				c = l;
			else if((V[l].k < V[r].k) || (V[l].k == V[r].k && V[l].i < V[r].i))
				c = l;
			else
				c = r;
			if((V[c].k < V[d].k) || (V[c].k == V[d].k && V[c].i < V[d].i))
				Swap(c , d);
			else
				break;
			d = c;
		}
	}
	inline void Insert(Node T){
		V[++siz] = T;
		PushUp(siz);
	}
	inline Node Delete(){
		Node T = V[1];
		V[1] = V[siz--];
		PushDown(1);
		return T;
	}
};

SmallRootHeap H;
Node T;
int n , ans;
long long a[Maxn];

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++)
		H.Insert((Node){i , Read()});
	memset(a , -1 , sizeof(long long) * (n + 1));
	while(H.siz >= 2){
		T = H.Delete();
		if(T.k != H.V[1].k){
			ans++;
			a[T.i] = T.k;
			continue;
		}
		H.V[1].k <<= 1;
		H.PushDown(1);
	}
	for(int i = 1 ; i <= H.siz ; i++)
		a[H.V[i].i] = H.V[i].k;
	printf("%d\n" , ans + H.siz);
	for(int i = 1 ; i <= n ; i++)
		if(a[i] > 0)
			printf("%lld " , a[i]);
	return 0;
}

// By Sooke.
// CF962D Merge Equals.