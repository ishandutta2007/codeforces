#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const int Maxb=330;
const int Maxv=(Maxn-1)/Maxb+1;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
int a[Maxn+5];
ll v[Maxn+5];
bool del[Maxn+5];
struct Block{
	int l,r;
	int st[Maxb+5],top;
	ll all_b;
	int all_k;
	struct Node{
		ll b;
	}val[Maxb+5];
	int id[Maxb+5];
	static bool cmp_id(int p,int q){
		return a[p]>a[q];
	}
	std::pair<ll,int> find_val(int p=-1){
		if(p==-1){
			if(top>0){
				p=st[top];
			}
			else{
				return std::make_pair(-Inf,0);
			}
		}
		return std::make_pair(1ll*a[p]*all_k+val[p-l+1].b+all_b,p);
	}
	void init(int _l=-1,int _r=-1){
		all_b=0;
		all_k=0;
		if(_l!=-1){
			l=_l;
			r=_r;
			for(int i=l;i<=r;i++){
				id[i-l+1]=i;
			}
			std::sort(id+1,id+1+(r-l+1),cmp_id);
		}
		top=0;
		for(int I=1;I<=r-l+1;I++){
			int i=id[I];
			if(del[i]){
				continue;
			}
			val[i-l+1].b=v[i];
			if(top==0||find_val(i).first>find_val(st[top]).first){
				st[++top]=i;
			}
		}
	}
	void add_b(int s){
		all_b+=s;
	}
	void add_k(int s){
		all_k+=s;
		while(top>1&&find_val(st[top]).first<=find_val(st[top-1]).first){
			top--;
		}
	}
	void print(int pos){
		all_b+=a[pos];
		for(int i=l;i<=r;i++){
			if(del[i]){
				continue;
			}
			if(i==pos){
				del[i]=1;
				all_b-=a[pos];
				all_k++;
				continue;
			}
			v[i]=find_val(i).first;
		}
	}
}block[Maxv+5];
int find_belong(int x){
	return (x-1)/Maxb+1;
}
int find_bel_l(int x){
	return (x-1)*Maxb+1;
}
int find_bel_r(int x){
	return std::min(n,x*Maxb);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[i]=a[i];
	}
	for(int i=1;i<=find_belong(n);i++){
		block[i].init(find_bel_l(i),find_bel_r(i));
	}
	std::pair<ll,int> maxn;
	ll ans=0,sum=0;
	for(int i=1;i<=n;i++){
		maxn=std::make_pair(-Inf,0);
		for(int j=1;j<=find_belong(n);j++){
			maxn=std::max(maxn,block[j].find_val());
		}
		sum+=maxn.first;
		ans=std::max(ans,sum);
		for(int j=1;j<find_belong(maxn.second);j++){
			block[j].add_b(a[maxn.second]);
		}
		for(int j=find_belong(maxn.second)+1;j<=find_belong(n);j++){
			block[j].add_k(1);
		}
		block[find_belong(maxn.second)].print(maxn.second);
		block[find_belong(maxn.second)].init();
	}
	printf("%lld\n",ans);
	return 0;
}