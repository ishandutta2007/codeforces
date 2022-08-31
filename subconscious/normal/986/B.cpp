#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=1e6+5,inf=0x3f3f3f3f;
int t[N];
void add(int p){for(;p<N;p+=p&-p)++t[p];}
int que(int p){int s=0;for(;p;p-=p&-p)s+=t[p];return s;}
int n,x;
int main(){
	scanf("%d",&n);
	ll s=0;
	rep(i,n){
		scanf("%d",&x),x=n-x+1;
		s+=que(x);add(x);
	}
	if(((1ll*n)^s)&1)puts("Um_nik");else puts("Petr");
	//system("pause");
	return 0;
}