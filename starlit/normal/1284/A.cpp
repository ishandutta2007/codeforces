#include<bits/stdc++.h>
const int N=30;
using namespace std;
int n,m,q,x;
char S[N][N],T[N][N];
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%s",S[i]);
	for(int i=0;i<m;i++)
	scanf("%s",T[i]);
	scanf("%d",&q);
	for(;q--;){
		scanf("%d",&x);
		x--;cout<<S[x%n]<<T[x%m]<<endl;
	}
}