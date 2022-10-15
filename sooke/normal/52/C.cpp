#include <cstdio>
#define Maxn 200001
#define Min(x , y) ((x) < (y) ? (x) : (y))

bool flag;

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
	flag = c == ' ';
	return f ? -n : n;
}

int n , m , a[Maxn];
long long _min;

struct SegmentTree{
	long long c[Maxn << 2] , s[Maxn << 2];
	void Build(int d , int l , int r){
		if(l == r)
			c[d] = a[l];
		else{
			int mid = l + r >> 1;
			Build(d << 1 , l , mid);
			Build(d << 1 | 1 , mid + 1 , r);	
			c[d] = Min(c[d << 1] , c[d << 1 | 1]);
			s[d] = 0;
		}
	}
	void Modify(int d , int l , int r , int pl , int pr , int k){
		if(pl == l && pr == r){
			c[d] += k;
			s[d] += k;
			return;
		}
		int mid = l + r >> 1;
		if(s[d] != 0){
			s[d << 1] += s[d] , s[d << 1 | 1] += s[d];
			c[d << 1] += s[d] , c[d << 1 | 1] += s[d];
			s[d] = 0;
		}
		if(pr <= mid)
			Modify(d << 1 , l , mid , pl , pr , k);
		else if(pl > mid)
			Modify(d << 1 | 1 , mid + 1 , r , pl , pr , k);
		else{
			Modify(d << 1 , l , mid , pl , mid , k);
			Modify(d << 1 | 1 , mid + 1 , r , mid + 1 , pr , k);
		}
		c[d] = Min(c[d << 1] , c[d << 1 | 1]);
	}
	void Query(int d , int l , int r , int pl , int pr){
		if(pl == l && pr == r){
			_min = Min(_min , c[d]);
			return;
		}
		int mid = l + r >> 1;
		if(s[d] != 0){
			s[d << 1] += s[d] , s[d << 1 | 1] += s[d];
			c[d << 1] += s[d] , c[d << 1 | 1] += s[d];
			s[d] = 0;
		}
		if(pr <= mid)
			Query(d << 1 , l , mid , pl , pr);
		else if(pl > mid)
			Query(d << 1 | 1 , mid + 1 , r , pl , pr);
		else{
			Query(d << 1 , l , mid , pl , mid);
			Query(d << 1 | 1 , mid + 1 , r , mid + 1 , pr);
		}
		c[d] = Min(c[d << 1] , c[d << 1 | 1]);
	}
};

SegmentTree T;

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++)
		a[i] = Read();
	T.Build(1 , 1 , n);
	m = Read();
	for(int i = 1 ; i <= m ; i++){
		int l = Read() + 1 , r = Read() + 1 , x;
		if(flag){
			x = Read();
			if(l <= r)
				T.Modify(1 , 1 , n , l , r , x);
			else{
				T.Modify(1 , 1 , n , 1 , r , x);
				T.Modify(1 , 1 , n , l , n , x);
			}
		}else{
			_min = 1LL << 62;
			if(l <= r)
				T.Query(1 , 1 , n , l , r);
			else{
				T.Query(1 , 1 , n , 1 , r);
				T.Query(1 , 1 , n , l , n);
			}
			printf("%lld\n" , _min);
		}
	}
	return 0;
}

// By Sooke.
// CF52C Circular RMQ.