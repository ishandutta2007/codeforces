#include <cstdio>
#define Maxn 500001
#define Abs(x) ((x) < 0 ? -(x) : (x))

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

struct BigRootHeap{
	int siz , a[Maxn];
	inline void PushUp(int d){
		while(d != 1 && a[d] > a[d >> 1]){
			int tmp = a[d];
			a[d] = a[d >> 1];
			a[d >> 1] = tmp;
			d >>= 1;
		}
	}
	inline void PushDown(int d){
		while(true){
			int l = d << 1 , r = l | 1 , c;
			if(l > siz)
				return;
			else if(r > siz)
				c = l;
			else if(a[l] > a[r])
				c = l;
			else
				c = r;
			if(a[c] > a[d]){
				int tmp = a[c];
				a[c] = a[d];
				a[d] = tmp;
			}else
				break;
			d = c;
		}
	}
	inline void Insert(int k){
		a[++siz] = k;
		PushUp(siz);
	}
	inline int Delete(){
		a[0] = a[1];
		a[1] = a[siz--];
		PushDown(1);
		return a[0];
	}
};

BigRootHeap H;
int n , k;
long long ans = 0;

int main(){
	for(n = Read() ; n >= 1 ; n--){
		k = Read();
		H.Insert(k);
		if(H.a[1] > k){
			int tmp = H.Delete();
			ans = ans + tmp - k;
			H.Insert(k);
		}
	}
	printf("%lld\n" , ans);
	return 0;
}

// By Sooke.
// WangXiangWen is Dalao %%%.
// CF13C Sequence.