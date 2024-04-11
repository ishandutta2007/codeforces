#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (1<<30)
struct Segment{
	int left,right;
}seg[1000005];
struct Node{
	int at;
	bool left_or_right;
	friend bool operator <(Node p,Node q){
		if(p.at==q.at){
			return p.left_or_right<q.left_or_right;
		}
		return p.at<q.at;
	}
};
vector<Node> node;
Node make(int at,bool left_or_right){
	Node ans;
	ans.at=at;
	ans.left_or_right=left_or_right;
	return ans;
}
int ans[1000005][2];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&seg[i].left,&seg[i].right);
		node.push_back(make(seg[i].left,0));
		node.push_back(make(seg[i].right,1));
	}
	sort(node.begin(),node.end());
	int left=INF;
	int ans_len=0;
	for(unsigned i=0;i<node.size();i++){
		if(node[i].left_or_right==0){
			k--;
			if(k==0){
				left=node[i].at;
			}
		}
		else{
			k++;
			if(k==1){
				ans[++ans_len][0]=left;
				ans[ans_len][1]=node[i].at;
				left=INF;
			}
		}
	}
	printf("%d\n",ans_len);
	for(int i=1;i<=ans_len;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}