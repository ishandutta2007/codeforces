#include <bits/stdc++.h>
using namespace std;
//Coded in Dongge Jifang 2
//IP address: 192.168.10.233
const int Inf=0x3f3f3f3f;
const int itmx=131072;
 
struct node{
	vector<int> vx;
	vector<long long> bit;
	int itmx;
	node(){
		vx.clear();
		bit.clear();
	}
	void upd(int p,int v){
		p=lower_bound(vx.begin(),vx.end(),p)-vx.begin()+1;
		while(p<=itmx){
			bit[p]+=v;
			p+=p&-p;
		}
	}
	long long getsum(int x){
		x=lower_bound(vx.begin(),vx.end(),x+1)-vx.begin();
		long long ans=0;
		while(x){
			ans+=bit[x];
			x-=x&-x;
		}
		return ans;
	}
}indt[300005];
 
int val[300005];
 
void upd(int p,int v){
	if(v==Inf){
		v=0;
	}
	if(val[p]){
		for(int i=itmx+p-1;i;i>>=1){
			indt[i].upd(val[p],p-val[p]);
		}
	}
	if(v){
		for(int i=itmx+p-1;i;i>>=1){
			indt[i].upd(v,v-p);
		}
	}
	val[p]=v;
}
 
long long getsum(int p,int pp){
	int P=p,PP=pp;
	p+=itmx-1;
	pp+=itmx-1;
	long long ans=0;
	for(;p<=pp;p>>=1,pp>>=1){
		if(p&1){
			ans+=indt[p++].getsum(PP);
		}
		if(!(pp&1)){
			ans+=indt[pp--].getsum(PP);
		}
	}
	return ans;
}
 
int a[100005],A[100005];
set<int> sp[100005];
int n,m;
int qry[100005][3];
 
int getnxt(int p){
	set<int>::iterator it=sp[a[p]].lower_bound(p+1);
	if(it==sp[a[p]].end()){
		return Inf;
	}
	return *it;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		A[i]=a[i];
		sp[a[i]].insert(i);
	}
	for(int i=1;i<=m;i++){
		cin>>qry[i][0]>>qry[i][1]>>qry[i][2];
	}
	for(int i=1;i<=n;i++){
		int p=getnxt(i);
		if(p==Inf){
			continue;
		}
		for(int j=itmx+i-1;j>=1;j>>=1){
			indt[j].vx.push_back(p);
		}
	}
	for(int i=1;i<=m;i++){
		if(qry[i][0]==2){
			continue;
		}
		int p=qry[i][1],x=qry[i][2];
		set<int>::iterator it=sp[a[p]].lower_bound(p);
		if(it!=sp[a[p]].begin()){
			set<int>::iterator it2=it;
			it2++;
			it--;
			if(it2!=sp[a[p]].end()){
				int y=*it,z=*it2;
				for(int j=itmx+y-1;j;j>>=1){
					indt[j].vx.push_back(z);
				}
			}
		}
		sp[a[p]].erase(p);
		a[p]=x;
		sp[a[p]].insert(p);
		it=sp[a[p]].lower_bound(p);
		if(it!=sp[a[p]].begin()){
			it--;
			int y=*it;
			for(int j=itmx+y-1;j;j>>=1){
				indt[j].vx.push_back(p);
			}
		}
		int pp=getnxt(p);
		if(pp!=Inf){
			for(int j=itmx+p-1;j;j>>=1){
				indt[j].vx.push_back(pp);
			}
		}
	}
	for(int i=1;i<=itmx*2;i++){
		sort(indt[i].vx.begin(),indt[i].vx.end());
		indt[i].vx.erase(unique(indt[i].vx.begin(),indt[i].vx.end()),indt[i].vx.end());
		int x=2;
		while(x<indt[i].vx.size()){
			x<<=1;
		}
		indt[i].itmx=x;
		indt[i].bit.resize(x+1);
	}
	for(int i=1;i<=n;i++){
		a[i]=A[i];
		sp[i].clear();
	}
	for(int i=1;i<=n;i++){
		sp[a[i]].insert(i);
	}
	for(int i=1;i<=n;i++){
		int p=getnxt(i);
		if(p!=Inf){
			upd(i,p);
		}
	}
	for(int i=1;i<=m;i++){
		int t1=qry[i][0],t2=qry[i][1],t3=qry[i][2];
		if(t1==1){
			int p=t2,x=t3;
			set<int>::iterator it=sp[a[p]].lower_bound(p);
			if(it!=sp[a[p]].begin()){
				int v=Inf;
				set<int>::iterator it2=it;
				it2++;
				it--;
				if(it2!=sp[a[p]].end()){
					v=*it2;
				}
				upd(*it,v);
			}
			sp[a[p]].erase(p);
			a[p]=x;
			sp[a[p]].insert(p);
			it=sp[a[p]].lower_bound(p);
			if(it!=sp[a[p]].begin()){
				it--;
				upd(*it,p);
			}
			upd(p,getnxt(p));
		}else{
			cout<<getsum(t2,t3)<<endl;
		}
	}
	return 0;
}