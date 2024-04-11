#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
struct Bus{
	int tim;
	int id;
	friend bool operator <(Bus p,Bus q){
		return p.tim<q.tim;
	}
}a[Maxn+5];
int s[Maxn+5],d[Maxn+5];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&d[i]);
		while(s[i]<t){
			s[i]+=d[i];
		}
		a[i].id=i;
		a[i].tim=s[i];
	}
	sort(a+1,a+1+n);
	printf("%d\n",a[1].id);
	return 0;
}