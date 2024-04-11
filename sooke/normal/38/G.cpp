#include <cstdio>
#define Maxn 100005
#define Max(x , y) ((x) > (y) ? (x) : (y))

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n;

struct Node{
	int i , k , mxk , siz , f , s[2];
};
struct SplayTree{
	Node V[Maxn];
	int siz , root;
	inline void Update(int d){
		V[d].siz = V[V[d].s[0]].siz + V[V[d].s[1]].siz + 1;
		V[d].mxk = Max(V[V[d].s[0]].mxk , V[V[d].s[1]].mxk);
		V[d].mxk = Max(V[d].mxk , V[d].k);
	}
	inline void Connect(int d , int f , int dir){
		V[d].f = f;
		V[f].s[dir] = d;
	}
	inline void Rotate(int d){
		int f , s , g , dir , fdir;
		f = V[d].f;
		g = V[f].f;
		dir = V[f].s[1] == d;
		fdir = V[g].s[1] == f;
		if(f == root)
			root = d;
		s = V[d].s[dir ^ 1];
		Connect(s , f , dir);
		Connect(f , d , dir ^ 1);
		Connect(d , g , fdir);
		Update(f);
		Update(d);
	}
	inline void Splay(int d , int fn){
		int f , g;
		while(V[d].f != fn){
			f = V[d].f;
			g = V[f].f;
			if(g != fn){
				if((V[f].s[1] == d) ^ (V[g].s[1] == f))
					Rotate(d);
				else
					Rotate(f);
			}
			Rotate(d);
		}
	}
	int Insert(int d , int rnk , int i , int k){
		if(d == 0){
			siz++;
			V[siz].i = i;
			V[siz].k = k;
			V[siz].mxk = k;
			V[siz].siz = 1;
			return siz;
		}
		if(V[V[d].s[0]].siz + 1 >= rnk){
			V[d].s[0] = Insert(V[d].s[0] , rnk , i , k);
			V[V[d].s[0]].f = d;
		}else{
			V[d].s[1] = Insert(V[d].s[1] , rnk - V[V[d].s[0]].siz - 1 , i , k);
			V[V[d].s[1]].f = d;
		}
		Update(d);
		return d;
	}
	int Find(int d , int rnk){
		if(V[V[d].s[0]].siz >= rnk)
			return Find(V[d].s[0] , rnk);
		else if(V[V[d].s[0]].siz + 1 < rnk)
			return Find(V[d].s[1] , rnk - V[V[d].s[0]].siz - 1);
		return d;
	}
	void Print(int d){
		if(d == 0)
			return;
		Print(V[d].s[0]);
		if(V[d].i > 0)
			printf("%d " , V[d].i);
		Print(V[d].s[1]);
	}
};

SplayTree T;

int main(){
	T.root = T.Insert(T.root , 1 , 0 , 0);
	T.Insert(T.root , 2 , 0 , 0);
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		int k = Read() , c = Read() , ans = i , dl , dr;
		dr = T.Find(T.root , i + 1);
		for(int l = Max(i - c , 1) , r = i - 1 , mid ; l <= r ; ){
			mid = l + r >> 1;
			dl = T.Find(T.root , mid);
			T.Splay(dl , 0);
			T.Splay(dr , dl);
			if(T.V[T.V[dr].s[0]].mxk < k)
				r = mid - 1 , ans = mid;
			else
				l = mid + 1;
		}
		T.Insert(T.root , ans + 1 , i , k); 
		T.Splay(i + 2 , 0);
	}
	T.Print(T.root);
	return 0;
}

// By Sooke.
// CF38G Queue.