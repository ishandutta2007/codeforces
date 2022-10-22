#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int o=1<<19;
struct Node{long long pre,suf,sum,ans;};
inline Node merge(const Node&A,const Node&B)
{return (Node){max(A.pre,A.sum+B.pre),max(B.suf,A.suf+B.sum),A.sum+B.sum,max(max(A.ans,B.ans),A.suf+B.pre)};}
int n,a[o],q,x,S;vector<Node> vec[o];
void build(int id,int l,int r){
	if(l==r){vec[id].push_back((Node){max(a[l],0),max(a[r],0),a[l],max(a[r],0)});return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	vec[id].reserve(r-l+1);
	for(int i=0;i<=(r-l)/2;++i) vec[id].push_back(merge(vec[id<<1][i],vec[(id<<1)|1][i]));
	for(int i=0;i<=(r-l)/2;++i) vec[id].push_back(merge(vec[(id<<1)|1][i],vec[id<<1][i]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);++i) scanf("%d",&a[i]);
	build(1,1,1<<n);
	for(scanf("%d",&q);q--;printf("%lld\n",vec[1][S].ans)) scanf("%d",&x),S^=(1<<x);
	return 0;
}