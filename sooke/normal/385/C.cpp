#include <cstdio>
#define Maxn 1000001
#define Maxk 10000002
#define Max(x , y) ((x) > (y) ? (x) : (y))
#define Min(x , y) ((x) < (y) ? (x) : (y))

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

int n , m , t , _max , cnt[Maxk] , f[Maxk];
bool vis[Maxk];

void Init(int d){
	for(register int i = 2 ; i <= d ; i++)
		if(!vis[i]){
			f[i] = cnt[i];
			for(register int j = (i << 1) ; j <= d ; j += i){
				vis[j] = true;
				f[i] += cnt[j];
			}
		}
	for(register int i = 3 ; i <= d ; i++)
		f[i] += f[i - 1];
}

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		t = Read();
		_max = Max(_max , t);
		cnt[t]++;
	}
	Init(++_max);
	m = Read();
	for(int i = 1 ; i <= m ; i++){
		int l = Read() , r = Read();
		l = Min(l - 1 , _max);
		r = Min(r , _max);
		printf("%d\n" , f[r] - f[l]);
	}
	return 0;
}

// By Sooke.
// CF385C Bear and Prime Numbers.