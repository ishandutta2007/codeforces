#include <cstdio>
 
struct List{
	int len , fir[400001] , nex[400001] , v[400001];
	inline void Init(int d){
		for(int i = 1 ; i <= d ; i++)
			fir[i] = -1;
		len = 0;
	}
	inline void Insert(int d , int dv){
		nex[len] = fir[d] , v[len] = dv;
		fir[d] = len++;
	}
};
 
List L;
long long n , x , y , ansx = 1 , ansy = 0 , siz[400001];
 
void DfsA(int d , int r){
	siz[d] = 1;
	for(int i = L.fir[d] ; i != -1 ; i = L.nex[i])
		if(L.v[i] != r)
			DfsA(L.v[i] , d),
			ansy += siz[L.v[i]],
			siz[d] += siz[L.v[i]];
}
void DfsB(int d , int r , long long cur){
	if(ansy < cur)
		ansx = d , ansy = cur;
	else if(ansy == cur)
		ansx = ansx > d ? d : ansx;
	for(int i = L.fir[d] ; i != -1 ; i = L.nex[i])
		if(L.v[i] != r)
			DfsB(L.v[i] , d , cur + siz[1] - (siz[L.v[i]] << 1));
}
 
int main(){
	scanf("%d" , &n);
	L.Init(n);
	for(int i = 2 ; i <= n ; i++)
		scanf("%d%d" , &x , &y),
		L.Insert(x , y),
		L.Insert(y , x);
	DfsA(1 , 0);
	DfsB(1 , 0 , ansy);
	printf("%I64d\n" , ansy + n);
	return 0;
}