#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
/*
bool chk(int x){
	vector<int> v;
	for(int i=2;i<x;i++){
		if(x%i==0){
			v.push_back(i);
		}
	}
	for(auto i: v) {
		for(auto j:v){
			if(gcd(i+j,x)==1){
				printf("solve %d %d %d\n", x, i, j); 
				//assert(x%30);
				return 1;
			}
		}
	}
	printf("solve %d, gg\n", x);
	return 0;
}
int main(){
	for(int i=1;i<=1000;i++)chk(i);
}
*/

const int N=10000000 + 10;
int mn[N];     
int prime[N / 2] = {0},num_prime = 0;      
bool isNotPrime[N] = {1, 1};//01 
void pri() {     
    for (int i = 1 ; i < N ; i ++)  {              
        if(! isNotPrime[i])   
            prime[num_prime ++]=i, mn[i]=i;
		for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)  {                 
            isNotPrime[i * prime[j]] = 1;
            mn[i * prime[j]] = prime[j];
        	if( !(i % prime[j] ) )  
           		break;             
    	}          
    }          
    return;
}

int a[500000 + 10], b[500000 + 10];
int main() {
	pri(); mn[1]=1;
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x); int y=x;
		vector<int> v;
		while(x){
			int tmp=mn[x]; if(tmp==1) break;
			v.push_back(tmp);
			while(x%tmp==0){
				x/=tmp;
			}
		}
		if(v.size()<=1) a[i]=-1, b[i]=-1;
		else {
			if(v[0]%2) a[i]=v[0],b[i]=v[1];
			else {
				a[i]=2; b[i]=1;
				for(int j=1;j<v.size();j++)b[i]*=v[j];
			}
		}
	}

	for(int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
}