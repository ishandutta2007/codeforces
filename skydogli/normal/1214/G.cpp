#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 2005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
bitset<MN>tmp,qwq,bit[MN];
int n,m,q,cnt[MN];
struct cmp{
	bool operator () (const int &a,const int &b){
		if(cnt[a]==cnt[b])return a<b;
		return cnt[a]<cnt[b];
	}
};
set<int,cmp>S;
#define itset set<int,cmp>::iterator
int now;
set<pii >mat;
void INS(int a){
	S.insert(a);
	itset it=S.find(a),il=it,ir=it;
	il--;ir++;
	if(cnt[*il]&&ir!=S.end()&&((bit[*il]&bit[*ir])!=bit[*il]))
		mat.erase(mp(*il,*ir));
	if(cnt[*il]&&((bit[*il]&bit[*it])!=bit[*il])){
		mat.insert(mp((*il),(*it)));
	}
	if(ir!=S.end()&&((bit[*it]&bit[*ir])!=bit[*it])){
		mat.insert(mp(*it,*ir));
	}
}
void DEL(int a){
	itset it=S.find(a),il=it,ir=it;
	il--;ir++;
	if(cnt[*il]&&ir!=S.end()&&((bit[*il]&bit[*ir])!=bit[*il]))
		mat.insert(mp(*il,*ir));
	if(cnt[*il]&&((bit[*il]&bit[*it])!=bit[*il]))mat.erase(mp((*il),(*it)));
	if(ir!=S.end()&&((bit[*it]&bit[*ir])!=bit[*it]))mat.erase(mp(*it,*ir));
	S.erase(a);
}
int main(){

	n=read();m=read();q=read();
	for(int i=0;i<=n;++i)S.insert(i);
	for(int i=1;i<=q;++i){
		int a=read(),l=read(),r=read();
		tmp.set();tmp>>=(MN-(r-l+1));tmp<<=l;
		DEL(a);
		bit[a]^=tmp;
		cnt[a]=bit[a].count();
		INS(a);
		if(!mat.size())puts("-1");
		else{
			pii w=*mat.begin();
			int x1=w.x,x2=w.y;
			qwq=bit[w.x]^bit[w.y];
			int y1=(qwq&bit[w.x])._Find_first();
			int y2=(qwq&bit[w.y])._Find_first();
			//y2=qwq._Find_next(y1);
			//			cerr<<"? "<<qwq<<endl;
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			printf("%d %d %d %d\n",x1,y1,x2,y2);
		}
	}
	return 0;
}