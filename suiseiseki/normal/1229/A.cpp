#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 7000
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
struct Student{
	ll a;
	int b;
	friend bool operator <(Student p,Student q){
		return p.a<q.a;
	}
}a[Maxn+5],b[Maxn+5];
int n;
int len;
bool vis[Maxn+5];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].a);
	}
	for(int i=1;i<=n;i++){
		read(a[i].b);
	}
	sort(a+1,a+1+n);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j].a==a[i].a){
			j++;
		}
		j--;
		if(j>i){
			for(int k=i;k<=j;k++){
				b[++len]=a[k];
				vis[k]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		for(int j=1;j<=len;j++){
			if((b[j].a|a[i].a)==b[j].a){
				b[++len]=a[i];
				break;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=len;i++){
		ans+=b[i].b;
	}
	cout<<ans<<endl;
	return 0;
}