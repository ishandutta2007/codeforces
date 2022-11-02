#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sum,res;

struct sb{
	int a,b,c,d,e,f,su;
	bool operator<(const sb x)const{
		return f>x.f;
	}
}s[200500];

string sb;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		if(n&1){
			if(k<(m/2)){puts("NO");goto aaa;}
			k-=(m/2);
			if(k&1){puts("NO");goto aaa;}
			else{puts("YES");goto aaa;}
			
		}
		if(m&1){
			if(k>(m/2)*n){puts("NO");goto aaa;}
			if(k&1){puts("NO");goto aaa;}
			else{puts("YES");goto aaa;}
			
		}
		
		{
			if(k&1){puts("NO");goto aaa;}
			else{puts("YES");goto aaa;}
			
		}
		
		aaa:;
	}
}