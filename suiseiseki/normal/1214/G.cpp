#include <set>
#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
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
const int Maxn=2000;
const int Maxq=500000;
struct Node{
	bitset<Maxn+5> val;
	int num,id;
	Node operator ^=(const bitset<Maxn+5>& a){
		val^=a;
		num=val.count();
		return (*this);
	}
	friend bool operator <(const Node &a,const Node &b){
		if(a.num==b.num){
			return a.id<b.id;
		}
		return a.num>b.num;
	}
}a[Maxn+5];
bitset<Maxn+5> all_one[Maxn+5];
int n,m,q;
int num;
pair<int,int> mp[Maxn+5];
set<pair<pair<int,int>,pair<int,int> > > st;
set<Node> lis;
void insert(set<Node>::iterator it){
	static bitset<Maxn+5> tmp;
	set<Node>::iterator nxt=it;
	nxt++;
	if(nxt==lis.end()){
		return;
	}
	tmp=(it->val)^(nxt->val);
	int pos_1,pos_2;
	pos_1=((it->val)&tmp)._Find_first();
	pos_2=((nxt->val)&tmp)._Find_first();
	if(pos_1!=(int)((it->val).size())&&pos_2!=(int)((nxt->val).size())){
		if(pos_1>pos_2){
			swap(pos_1,pos_2);
		}
		mp[it->id]=make_pair(pos_1,pos_2);
		if((it->id)>(nxt->id)){
			st.insert(make_pair(make_pair(nxt->id,it->id),mp[it->id]));
		}
		else{
			st.insert(make_pair(make_pair(it->id,nxt->id),mp[it->id]));
		}
	}
}
void remove(set<Node>::iterator it){
	set<Node>::iterator nxt=it;
	nxt++;
	if(mp[it->id].first==-1||nxt==lis.end()){
		return;
	}
	if((it->id)>(nxt->id)){
		st.erase(make_pair(make_pair(nxt->id,it->id),mp[it->id]));
	}
	else{
		st.erase(make_pair(make_pair(it->id,nxt->id),mp[it->id]));
	}
	mp[it->id]=make_pair(-1,-1);
}
void del(int x){
	set<Node>::iterator it;
	it=lis.find(a[x]);
	if(it!=lis.begin()){
		it--;
		remove(it);
		it++;
	}
	remove(it);
	if(it!=lis.begin()){
		it--;
		lis.erase(a[x]);
		insert(it);
	}
	else{
		lis.erase(a[x]);
	}
}
void add(int x){
	set<Node>::iterator it;
	it=lis.lower_bound(a[x]);
	if(it!=lis.begin()){
		it--;
		remove(it);
		it++;
	}
	lis.insert(a[x]);
	it=lis.find(a[x]);
	if(it!=lis.begin()){
		it--;
		insert(it);
		it++;
	}
	insert(it);
}
int main(){
	read(n),read(m),read(q);
	for(int i=1;i<n;i++){
		mp[i]=make_pair(-1,-1);
	}
	for(int i=1;i<=n;i++){
		a[i].id=i;
		add(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			all_one[i][j]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,l,r;
		read(x),read(l),read(r);
		del(x);
		a[x]^=((all_one[r]>>l)<<l);
		add(x);
		if(st.empty()){
			puts("-1");
		}
		else{
			set<pair<pair<int,int>,pair<int,int> > >::iterator it=st.begin();
			printf("%d %d %d %d\n",(it->first).first,(it->second).first,(it->first).second,(it->second).second);
		}
	}
	return 0;
}