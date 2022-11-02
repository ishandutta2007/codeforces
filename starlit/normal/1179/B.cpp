#include<bits/stdc++.h>
#define pr(xx,yy) printf("%d %d\n",(t?n-(xx)+1:(xx))+px,(t?m-(yy)+1:(yy))+py)
using namespace std;
typedef long long ll;
void sol(int n,int m,bool t,int px,int py){
	if(n==0||m==0)return;
	if(n==1){
		for(int i=1;i<=m+1>>1;i++){
			pr(1,i);
			if(m-i+1!=i)pr(1,m-i+1);
		}
		return;
	}
	if(m==1){
		for(int i=1;i<=n+1>>1;i++){
			pr(i,1);
			if(n-i+1!=i)pr(n-i+1,1);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		pr(i,1),pr(n-i+1,m);
	}
	for(int i=2;i<m;i++){
		pr(n,i),pr(1,m-i+1);
	}
	sol(n-2,m-2,t^1,px+1,py+1);
}
int n,m;
int main(){
	//freopen("dat.txt","w",stdout);
	scanf("%d%d",&n,&m);
	//cout<<n<<' '<<m<<endl;
	sol(n,m,0,0,0);
}