#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 200000
int mx(int a,int b){
	return a>b?a:b;
}
struct Node{
	int x,y;
	int id(){
		return mx(x,y);
	}
	friend bool operator <(Node p,Node q){
		return p.id()<q.id();
	}
}a[Maxn+5];
ll f[Maxn+5][2];
Node p[Maxn+5][2];
bool go_left(Node a,Node b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}
bool go_right(Node a,Node b){
	return a.y==b.y?a.x>b.x:a.y<b.y;
}
int ab(int a){
	return a<0?-a:a;
}
ll dist(Node a,Node b){
	return ab(a.x-b.x)+ab(a.y-b.y);
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n);
	memset(f,0x3f,sizeof f);
	f[0][1]=f[0][0]=0;
	int k=1;
	for(int i=1,j=1;i<=n;i=j+1,j++,k++){
		while(j<n&&a[j].id()==a[j+1].id()){
			j++;
		}
		p[k][0]=p[k][1]=a[i];
		for(int l=i+1;l<=j;l++){
			if(go_left(a[l],p[k][0])){
				p[k][0]=a[l];
			}
			if(go_right(a[l],p[k][1])){
				p[k][1]=a[l];
			}
		}
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				f[k][x]=mn(f[k][x],f[k-1][y]+dist(p[k-1][y],p[k][!x])+dist(p[k][!x],p[k][x]));
			}
		}
	}
	cout<<mn(f[k-1][0],f[k-1][1])<<endl;
	return 0;
}