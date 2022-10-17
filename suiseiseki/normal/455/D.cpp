#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=350;
int read(){
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans;
}
int n,Q,op,a[N];
int block,pos[N],m;
struct _Blo{
	int l,r,c[N];
} b[M];
deque<int> q[M];
deque<int>::iterator it;
void ini(){
	block=pow(n,0.618);
	m=(n-1)/block+1;
	for(int i=1;i<=n;i++){
		pos[i]=(i-1)/block+1;
	}
	for(int i=1;i<=m;i++){
		b[i].l=(i-1)*block+1;
		b[i].r=i*block;
	}
	b[m].r=n;
}
struct Block{
	void Set(int x){
		for(int i=b[x].l;i<=b[x].r;i++){
			q[x].push_back(a[i]);
			b[x].c[a[i]]++;
		}
	}
	void Cha(int l,int r){
		int pl=pos[l],pr=pos[r];
		int f=l-b[pl].l,g=r-b[pr].l,x=q[pr][g];
		if(pl==pr){
			q[pr].erase(q[pr].begin()+g);
			q[pl].insert(q[pl].begin()+f,x);
		}
		else{
			q[pl].insert(q[pl].begin()+f,x);
			b[pl].c[x]++;
			q[pr].erase(q[pr].begin()+g);
			b[pr].c[x]--;
			for(int i=pl;i<pr;i++){
				int x=q[i].back();
				q[i].pop_back();
				b[i].c[x]--;
				q[i+1].push_front(x);
				b[i+1].c[x]++;
			}
		}
	}
	int Que(int l,int r,int k){
		int pl=pos[l],pr=pos[r];
		int f=l-b[pl].l,g=r-b[pr].l;
		int ans=0;
		if(pl==pr){
			for(int i=f;i<=g;i++){
				ans+=(q[pl][i]==k);
			}
		}
		else{
			for(int i=f;i<(int)q[pl].size();i++){
				ans+=(q[pl][i]==k);
			}
			for(int i=0;i<=g;i++){
				ans+=(q[pr][i]==k);
			}
			for(int i=pl+1;i<pr;i++){
				ans+=b[i].c[k];
			}
		}
		return ans;
	}
}B;
int main(){
	n=read();
	ini();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		B.Set(i);
	}
	Q=read();
	int last=0,l,r;
	while(Q--){
		op=read();
		l=(read()+last-1)%n+1;
		r=(read()+last-1)%n+1;
		if(l>r){
			swap(l,r);
		}
		if(op==1){
			B.Cha(l,r);
		}
		else{
			int k=(read()+last-1)%n+1;
			last=B.Que(l,r,k);
			printf("%d\n",last);
		}
	}
	return 0;
}