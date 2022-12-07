#include <bits/stdc++.h>
#define double long double
using namespace std;
const int P=1000;
const int M=10*P; // more than enough
const int N=250;
const double inf=1e18;
int a[N];
double lg[M];
double ls[M];
double pois(int k,int p){
	if(k<0) return -inf;
	if(k==0) return -p;
	return k*lg[p]-p-ls[k];
}
double unif(int k,int p){
	if(k<0 or k>2*p) return -inf; 
	return -lg[2*p+1];
}
double sum_pois(int p){
	double res=0;
	for(int i=0;i<N;++i) res+=pois(a[i],p);
	return res;
}
double sum_unif(int p){
	double res=0;
	for(int i=0;i<N;++i) res+=unif(a[i],p);
	return res;
}
int main(){
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	ls[1]=lg[1]=0;
	for(int i=2;i<M;++i){
		lg[i]=logl(i);
		ls[i]=ls[i-1]+lg[i];
	}
	int t;
	cin >> t;
	while(t--){
		for(int i=0;i<N;++i){
			cin >> a[i];
		}
		double p_unif=-inf, p_pois=-inf, tmp;
		int pp, pu;
		for(int p=10;p<=1000;++p){
			tmp=sum_pois(p);
			if(p_pois<tmp){
				p_pois=tmp;
				pp=p;
			}
			tmp=sum_unif(p);
			if(p_unif<tmp){
				p_unif=tmp;
				pu=p;
			}
		}
		if(p_pois>p_unif) cout << pp << '\n';
		else cout << pu << '\n';
	}
	return 0;
}