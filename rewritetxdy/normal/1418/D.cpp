#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;

int n,m,c[N],l,r;

set<int>s;
set<int>::iterator it;
priority_queue<int>q;
unordered_map<int,int>vis;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]) , s.insert(c[i]);
	sort(c+1,c+1+n);
	l = c[1] , r = c[n];
	for(int i=2;i <= n;i++) q.push(c[i]-c[i-1]);
	while(!q.empty() && vis[q.top()]) vis[q.top()]-- , q.pop();
	printf("%d\n",q.empty() ? 0 : r-l-q.top());
	while(m--){
		int t,x;
		scanf("%d%d",&t,&x);
		it = s.upper_bound(x);
		if(t){
			if(!s.empty()){
				if(it == s.end()) r = x , q.push(x-*(--it));
				else if(it == s.begin()) l = x , q.push(*it-x);
				else --it , vis[*s.upper_bound(x)-*it]++ , q.push(*s.upper_bound(x)-x) , q.push(x-*it);
			}
			s.insert(x);
			if(l == -1) l = r = x;
		}
		else{
			s.erase(x);
			if(!s.empty()){
				if(x == l) l = *it , vis[*it-x]++;
				else if(x == r) r = *(--it) , vis[x-*it]++;
				else --it , vis[*s.upper_bound(x)-x]++ , vis[x-*it]++ , q.push(*s.upper_bound(x)-*it);
			}
			else l = -1;
		}
		while(!q.empty() && vis[q.top()]) vis[q.top()]-- , q.pop();
		printf("%d\n",q.empty() ? 0 : r-l-q.top());
	}
	return 0;
}