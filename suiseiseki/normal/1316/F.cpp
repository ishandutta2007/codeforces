#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
void read(int &a){
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
const int Maxn=300000;
const int Mod=1000000007;
const int Inf=1000000000;
struct Question{
	int x,v;
}qu[Maxn+5];
struct Segment_Node{
	int lson,rson;
	int l_val,r_val;
	int sz,val;
}seg[(Maxn<<3)+5];
multimap<int,int> mp;
int p[Maxn+5];
int pos[Maxn<<1|5];
int Root,id_tot;
int power_2[Maxn+5],inv_2[Maxn+5];
void init(){
	power_2[0]=1;
	inv_2[0]=1;
	power_2[1]=2;
	inv_2[1]=quick_power(2,Mod-2,Mod);
	for(int i=2;i<=Maxn;i++){
		inv_2[i]=1ll*inv_2[i-1]*inv_2[1]%Mod;
		power_2[i]=(power_2[i-1]<<1)%Mod;
	}
}
void push_up(int root){
	seg[root].sz=seg[seg[root].lson].sz+seg[seg[root].rson].sz;
	seg[root].l_val=(seg[seg[root].lson].l_val+1ll*seg[seg[root].rson].l_val*power_2[seg[seg[root].lson].sz]%Mod)%Mod;
	seg[root].r_val=(seg[seg[root].lson].r_val+1ll*seg[seg[root].rson].r_val*inv_2[seg[seg[root].lson].sz]%Mod)%Mod;
	seg[root].val=(seg[seg[root].lson].val+seg[seg[root].rson].val+1ll*seg[seg[root].lson].l_val*seg[seg[root].rson].r_val%Mod*inv_2[seg[seg[root].lson].sz]%Mod)%Mod;
}
void insert(int x,int a,int &root=Root,int left=1,int right=Inf){
	if(root==0){
		root=++id_tot;
	}
	if(left==right){
		if(a==1){
			seg[root].sz=1;
			seg[root].l_val=pos[x];
			seg[root].r_val=1ll*pos[x]*inv_2[1]%Mod;
			seg[root].val=0;
		}
		else{
			seg[root].sz=0;
			seg[root].l_val=0;
			seg[root].r_val=0;
			seg[root].val=0;
		}
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(x,a,seg[root].lson,left,mid);
	}
	else{
		insert(x,a,seg[root].rson,mid+1,right);
	}
	push_up(root);
}
int main(){
	init();
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(p[i]);
		mp.insert(make_pair(p[i],0));
	}
	int q;
	read(q);
	for(int i=1;i<=q;i++){
		read(qu[i].x);
		read(qu[i].v);
		mp.insert(make_pair(qu[i].v,0));
	}
	multimap<int,int>::iterator it;
	it=mp.begin();
	int id_tot=0;
	while(it!=mp.end()){
		(it->second)=++id_tot;
		pos[id_tot]=(it->first);
		it++;
	}
	for(int i=1;i<=n;i++){
		it=mp.lower_bound(p[i]);
		p[i]=(it->second);
		mp.erase(it);
	}
	for(int i=1;i<=q;i++){
		it=mp.lower_bound(qu[i].v);
		qu[i].v=(it->second);
		mp.erase(it);
	}
	for(int i=1;i<=n;i++){
		insert(p[i],1);
	}
	printf("%d\n",seg[Root].val);
	for(int i=1;i<=q;i++){
		insert(p[qu[i].x],-1);
		p[qu[i].x]=qu[i].v;
		insert(p[qu[i].x],1);
		printf("%d\n",seg[Root].val);
	}
	return 0;
}