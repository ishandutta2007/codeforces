#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
struct Node{
	int x,y;
	friend bool operator <(Node p,Node q){
		if(p.y==q.y){
			return p.x<q.x;
		}
		return p.y>q.y;
	}
}a[Maxn+5];
int n;
int b[Maxn<<1|5],len;
int f[Maxn<<1|5];
bool vis[Maxn<<1|5];
void add(int x,int a){
	for(int i=x;i<=len;i+=(i&(-i))){
		f[i]+=a;
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		b[++len]=a[i].x;
		b[++len]=a[i].y;
	}
	sort(b+1,b+1+len);
	len=unique(b+1,b+1+len)-b-1;
	for(int i=1;i<=n;i++){
		a[i].x=lower_bound(b+1,b+1+len,a[i].x)-b;
		a[i].y=lower_bound(b+1,b+1+len,a[i].y)-b;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	int maxn=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j].y==a[i].y){
			j++;
		}
		j--;
		for(int k=i;k<=j;k++){
			if(!vis[a[k].x]){
				vis[a[k].x]=1;
				add(a[k].x,1);
			}
			ans+=query(a[k].x);
			if(k<j){
				ans+=1ll*(query(a[k+1].x-1)-query(a[k].x))*query(a[k].x);
			}
		}
		if(maxn<=a[j].x){
			maxn=a[j].x;
		}
		else{
			ans+=1ll*(query(maxn)-query(a[j].x))*query(a[j].x);
		}
	}
	cout<<ans<<endl;
	return 0;
}