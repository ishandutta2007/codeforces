#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
ll s[Maxn+5];
ll a[Maxn+5];
ll f[Maxn+5];
int n;
void add(int x,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		f[i]+=a;
	}
}
ll query(int x){
	ll ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int fa[Maxn+5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		add(i+1,i);
		fa[i]=i;
	}
	int left,right,mid;
	int x;
	for(int i=n;i>0;i--){
		left=1,right=n;
		while(left<right){
			mid=(left+right)>>1;
			if(query(mid)>=s[i]){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		x=find(left);
		a[i]=x;
		add(x+1,-x);
		merge(x+1,x);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}