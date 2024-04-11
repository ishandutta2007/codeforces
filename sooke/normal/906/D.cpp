#include <cstdio>
#define Maxn 100005
#define M(x , y) ((x) < (y) ? (x) : (x) % (y) + (y))

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , m , q , t , eul[100];
long long a[Maxn];

inline int Euler(int k){
	int res = k;
	for(int i = 2 ; i * i <= k ; i++)
		if(k % i == 0){
			res = res / i * (i - 1);
			while(k % i == 0)
				k = k / i;
		}
	return k == 1 ? res : res / k * (k - 1);
}
inline int Pow(long long k , int d , int p){
	long long res = 1;
	while(d > 0){
		if(d & 1)
			res = M(res * k , p);
		k = M(k * k , p);
		d >>= 1;
	}
	return res;
}
int Solve(int d , int l , int r , int p){
	if(l == r || p == 1)
		return M(a[l] , p);
	int ans = Solve(d + 1 , l + 1 , r , eul[d]);
	return Pow(a[l] , ans , p);
}

int main(){
	n = Read() , m = Read();
	eul[0] = m;
	for(t = 1 ; eul[t - 1] != 1 ; t++)
		eul[t] = Euler(eul[t - 1]);
	for(int i = 1 ; i <= n ; i++)
		a[i] = Read();
	q = Read();
	for(int i = 1 ; i <= q ; i++){
		int l = Read() , r = Read();
		printf("%d\n" , Solve(1 , l , r , m) % m);
	}
	return 0;
}

// By Sooke.
// CF906D Power Tower.