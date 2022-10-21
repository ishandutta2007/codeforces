#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int INT_max = 2147483647;
const int INT_min = -2147483647;

const ll INF = 9223372036854775807;
const int MAXn = 200000;

int lar[2 * MAXn - 1];
int sma[2 * MAXn - 1];
int num[MAXn];
int streesize;

void init(int n_){
	streesize = 1;
	while(streesize < n_) streesize *= 2;
	for(int i = 0; i < 2 * streesize -1; i++){
		lar[i] = -2000000000;
		sma[i] = 2000000000;
	}
	//printf("n = %d\n", streesize);
}

void update(int k, int a){
	k += streesize - 1;
	lar[k] = a;
	sma[k] = a;
	while(k > 0){
		k = (k-1) / 2;
		lar[k] = max(lar[k*2+1], lar[k*2+2]);
		sma[k] = min(sma[k*2+1], sma[k*2+2]);
	}
}

int querylar(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return INT_min;
	if(a <= l && r <= b) return lar[k];
	else{
		int vl = querylar(a,b,k*2+1,l,(l+r)/2);
		int vr = querylar(a,b,k*2+2,(l+r)/2,r);
		//printf("returning vl = %d vr= %d\n", vl,vr);
		return max(vl,vr);
	}
}

int querysma(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return INT_max;
	if(a <= l && r <= b) return sma[k];
	else{
		int vl = querysma(a,b,k*2+1,l,(l+r)/2);
		int vr = querysma(a,b,k*2+2,(l+r)/2,r);
		//printf("returning vl = %d vr= %d\n", vl,vr);
		return min(vl,vr);
	}
}

int main(){
	int n,p,q,r;
	scanf("%d%d%d%d",&n,&p,&q,&r);
	init(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		update(i, num[i]);
	}
	ll res = -INF;
	for(int i = 0; i < n; i++){
		ll sum = 0;
		sum += (ll)q * num[i];
		if(p > 0){
			sum += (ll)p * querylar(0,i+1,0,0,streesize);
		}
		else{
			sum += (ll)p * querysma(0,i+1,0,0,streesize);
		}
		if(r > 0){
			sum += (ll)r * querylar(i,n,0,0,streesize);
		}
		else{
			sum += (ll)r * querysma(i,n,0,0,streesize);
		}
		//printf("num[%d] = %d lar(0,%d) = %d lar(%d,%d) = %d\n", i, num[i], i+1, querylar(0,i+1,0,0,streesize),i, n,querylar(i,n,0,0,streesize));
		res = max(res, sum);
	}
	cout<<res;
	
}