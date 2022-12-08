#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

set<int> s;
int p[100005],e[100005],tot;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void get(int x,int y){
	if(x==tot+1){
//		printf("%d\n",y);
		s.insert(y);
		return ;
	}
	int t=y;
	for(int i=0;i<=e[x];i++){
		get(x+1,t);
		t=t*p[x];
	}
}
		

int main(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=gcd(a,b);
	for(int i=2;i*i<=c;i++){
		if(c%i==0){
			tot++;
			p[tot]=i;
			while(c%i==0){
				e[tot]++;
				c/=i;
			}
		}
	}
	if(c>1){
		tot++;
		p[tot]=c;
		e[tot]=1;
	}
	get(1,1);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int high,low;
		scanf("%d%d",&low,&high);
		set<int>::iterator it;
		it=lower_bound(s.begin(),s.end(),low);
//		printf("%d\n",*it);
		bool isok=false;
		int ans=0;
		for(;it!=s.end()&&(*it<=high);it++)
			ans=*it,isok=true;
		if(isok) printf("%d\n",ans); else printf("-1\n");
	}
	return 0;
}