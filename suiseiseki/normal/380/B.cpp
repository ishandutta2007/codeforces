#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 7000
#define Maxm 200000
struct Node{
	int left,right;
	int val;
	Node(){}
	Node(int _left,int _right,int _val){
		left=_left;
		right=_right;
		val=_val;
	}
};
int n,m;
int dl[Maxm+5],dr[Maxm+5];;
vector<Node> v[Maxn+5];
int solve(int d,int x,int y){
	set<int> ans;
	Node tmp;
	for(int i=d;i<=n;i++){
		for(int j=0;j<(int)v[i].size();j++){
			tmp=v[i][j];
			if(tmp.left<=y&&tmp.right>=x){
				ans.insert(tmp.val);
			}
		}
		x=(dl[x]==-1?dr[x]:dl[x]);
		y=dr[y];
	}
	return (int)ans.size();
}
void init(){
	int cnt=1,p=3;
	memset(dl,-1,sizeof dl);
	memset(dr,-1,sizeof dr);
	dl[1]=1;
	dr[1]=2;
	for(int i=2;i<Maxm;i++){
		if((1<<cnt)==i){
			cnt++;
			dl[i]=p;
			p++;
		}
		dr[i]=p;
		p++;
	}
}
int main(){
	init();
	int op;
	int d,left,right,val;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d%d%d",&d,&left,&right,&val);
			v[d].push_back(Node(left,right,val));
		}
		else{
			scanf("%d%d",&d,&left);
			printf("%d\n",solve(d,left,left));
		}
	}
	return 0;
}