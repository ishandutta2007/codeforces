#include<bits/stdc++.h>
using namespace std;

const int N=500005;
struct fe{
	int tp,x;
}a[N];
int m,q,p[N],num[N];
char S[10];
long long tr[N];
set<long long> s;
void add(int x,int w){
	x++;
	for(;x<=m;x+=x&-x)tr[x]+=w;
}
long long get(int x){
	x++;
	long long ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}
int main(){
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%s",S);
		a[i].tp=(S[0]=='+');
		scanf("%d",&a[i].x);
		p[i]=a[i].x;
	}
	sort(p,p+q);
	m=unique(p,p+q)-p;
	int cnt=0;
	for(int i=0;i<q;i++){
		int u=lower_bound(p,p+m,a[i].x)-p;
		if(a[i].tp){
			if(!num[u])s.insert(a[i].x);
			add(u,a[i].x);
			num[u]++;cnt++;
		}else{
			num[u]--;cnt--;
			add(u,-a[i].x);
			if(!num[u])s.erase(a[i].x);
		}
		int ans=cnt-1;
		if(cnt==0){
			printf("0\n");
			continue;
		}
		long long sum=*s.begin();
		while(1){
			set<long long>::iterator it=s.upper_bound(sum*2);
			if(it==s.end())break;
			int u=lower_bound(p,p+m,*it)-p;
			long long s=get(u-1);
			if(s*2<*it)ans--;
			sum=get(u);
		}
		printf("%d\n",ans);
	}
	return 0;
}