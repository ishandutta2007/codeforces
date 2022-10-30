#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int a[100005],nxt[100005],lst[100005],vis[100005];
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
queue <int> q;
vector <int> ans;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		ans.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[i]=0;
		for(int i=1;i<n;i++) nxt[i]=i+1;
		for(int i=2;i<=n;i++) lst[i]=i-1;
		nxt[n]=1,lst[1]=n;
		for(int i=1;i<=n;i++)
			if(gcd(a[i],a[nxt[i]])==1) q.push(nxt[i]);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(vis[x]) continue;
			ans.push_back(x),vis[x]=1;
			if(!q.empty()&&q.front()==nxt[x]) q.pop();
			if(gcd(a[lst[x]],a[nxt[x]])==1)
				q.push(nxt[x]);
			nxt[lst[x]]=nxt[x],lst[nxt[x]]=lst[x];
		}
		cout << ans.size() << " ";
		for(auto t:ans) printf("%d ",t);
		puts("");
	}
	return 0;
}