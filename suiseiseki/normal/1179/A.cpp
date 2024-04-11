#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
deque<int> q;
int ans[Maxn+5][2],len;
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	int p=0;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q.push_back(a[i]);
		if(a[i]>a[p]){
			p=i;
		}
	}
	len=p-1;
	int x,y;
	for(int i=1;i<=len;i++){
		x=q.front();
		q.pop_front();
		y=q.front();
		q.pop_front();
		ans[i][0]=x;
		ans[i][1]=y;
		if(x>y){
			q.push_front(x);
			q.push_back(y);
		}
		else{
			q.push_front(y);
			q.push_back(x);
		}
	}
	ll m;
	while(t--){
		cin>>m;
		if(m<=len){
			printf("%d %d\n",ans[m][0],ans[m][1]);
			continue;
		}
		m-=len;
		m%=n-1;
		if(m==0){
			m=n-1;
		}
		printf("%d %d\n",q[0],q[m]);
	}
	return 0;
}