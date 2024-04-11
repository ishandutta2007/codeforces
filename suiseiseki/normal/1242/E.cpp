#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=300000;
struct Node{
	int x,id;
	friend bool operator <(Node a,Node b){
		if(a.x==b.x){
			return a.id<b.id;
		}
		return a.x>b.x;
	}
}a[Maxn+5];
deque<int> q;
vector<int> edge[Maxn+5];
int main(){
	int f;
	scanf("%d",&f);
	for(int i=1;i<=f;i++){
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+1+f);
	int n=0;
	for(int i=1;i<=a[1].x;i++){
		n++;
		q.push_back(n);
		edge[a[1].id].push_back(n);
	}
	for(int i=2;i<=f;i++){
		int e,k;
		e=a[i].x;
		k=a[i].id;
		int p=min(e-1,((int)q.size()+e-(i==f?3:a[i+1].x))/2);
		for(int j=0;j<p-1;j++){
			edge[k].push_back(q.back());
			q.pop_back();
		}
		edge[k].push_back(q.back());
		for(int j=p;j<e-1;j++){
			n++;
			edge[k].push_back(n);
			q.push_back(n);
		}
		edge[k].push_back(q.front());
		q.push_back(q.front());
		q.pop_front();
	}
	printf("%d\n",n);
	for(int i=1;i<=f;i++){
		for(int j=0;j<(int)edge[i].size();j++){
			printf("%d ",edge[i][j]);
		}
		puts("");
	}
	return 0;
}