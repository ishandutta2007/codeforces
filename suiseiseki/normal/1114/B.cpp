#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
struct Node{
	int a;
	int id;
	bool ok;
	friend bool operator <(Node p,Node q){
		return p.a>q.a;
	}
}a[Maxn+5];
int an[Maxn+5];
bool cmp(Node p,Node q){
	return p.id<q.id;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		a[i].id=i;
		a[i].ok=0;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=m*k;i++){
		ans+=a[i].a;
		a[i].ok=1;
	}
	sort(a+1,a+1+n,cmp);
	int now;
	int len=0;
	for(int i=1,j;i<=n&&len<k-1;i=j){
		now=0;
		j=i;
		while(now<m){
			if(a[j].ok){
				now++;
			}
			j++;
		}
		an[++len]=j-1;
	}
	cout<<ans<<endl;
	for(int i=1;i<=len;i++){
		printf("%d ",an[i]);
	}
	puts("");
	return 0;
}