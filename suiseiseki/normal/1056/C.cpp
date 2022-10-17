#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 2000
struct Hero{
	int power;
	int attack;
	int id;
	friend bool operator <(Hero p,Hero q){
		if(p.attack==0&&q.attack==0){
			return p.power>q.power;
		}
		if(p.attack!=0&&q.attack!=0){
			return p.power>q.power;
		}
		if(p.attack!=0){
			return 1;
		}
		return 0;
	}
}a[Maxn+5];
bool use[Maxn+5];
int ys[Maxn+5];
int main(){
	fflush(stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n<<1);i++){
		scanf("%d",&a[i].power);
		a[i].id=i;
		a[i].attack=0;
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x].attack=y;
		a[y].attack=x;
	}
	sort(a+1,a+1+(n<<1));
	for(int i=1;i<=(n<<1);i++){
		ys[a[i].id]=i;
	}
	int t;
	scanf("%d",&t);
	if(t==1){
		for(int i=1,j=1;i<=n;i++){
			while(use[a[j].id]){
				j++;
			}
			use[a[j].id]=1;
			cout<<a[j].id<<endl;
			scanf("%d",&x);
			use[x]=1;
		}
	}
	else{
		for(int i=1,j=1;i<=n;i++){
			scanf("%d",&x);
			use[x]=1;
			if(a[ys[x]].attack!=0&&!use[a[ys[x]].attack]){
				use[a[ys[x]].attack]=1;
				cout<<a[ys[x]].attack<<endl;
			}
			else{
				while(use[a[j].id]){
					j++;
				}
				cout<<a[j].id<<endl;
				use[a[j].id]=1;
			}
		}
	}
	return 0;
}