#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll a[100005];
ll mx(ll a,ll b){
	return a>b?a:b;
}
int father[100005];
int jx;
int find(int x){
	if(x==father[x]){
		return x;
	}
	return father[x]=find(father[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	father[fa_y]=fa_x;
	jx--;
}
int main(){
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
		father[i]=i;
		if(a[i]>l){
			jx++;
			if(a[i-1]>l){
				merge(i,i-1);
			}
		}
	}
	int c,y;
	while(m--){
		scanf("%d",&c);
		if(c==1){
			scanf("%d%d",&x,&y);
			if(a[x]<=l){
				a[x]+=y;
				if(a[x]>l){
					jx++;
					if(a[x-1]>l){
						merge(x,x-1);
					}
					if(a[x+1]>l){
						merge(x,x+1);
					}
				}
			}
			else{
				a[x]+=y;
			}
		}
		else{
			printf("%d\n",jx);
		}
	}
	return 0;
}