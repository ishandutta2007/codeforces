#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<int,int> step,last,rstep,rlast;
queue<int> q;
int x,y,p,siz,tmp;
inline int inv(long long a)
{
	long long ret=1;
	int b=p-2;
	while(b)
	{
		if(b&1)ret*=a,ret%=p;
		a*=a,a%=p;
		b>>=1;
	}
	return ret;
}
pair<int,int> arr[2333333];
int ord[233],otop;
vector<int> ans;
inline int getop(int a,int b)
{
	if(b==(a+1)%p)return 1;
	if(b==(a+p-1)%p)return 2;
	return 3;
}
int main()
{
	scanf("%d%d%d",&x,&y,&p);
	step[x]=1;last[x]=-1;
	q.push(x);siz++;
	while(!q.empty()&&siz<=100000)
	{
		int u=q.front();q.pop();
		if(!step[(u+1)%p])
		{
			step[(u+1)%p]=step[u]+1;
			last[(u+1)%p]=u;
			q.push((u+1)%p);
			siz++;
		}
		if(!step[(u+p-1)%p])
		{
			step[(u+p-1)%p]=step[u]+1;
			last[(u+p-1)%p]=u;
			q.push((u+p-1)%p);
			siz++;
		}
		tmp=inv(u);
		if(!step[tmp])
		{
			step[tmp]=step[u]+1;
			last[tmp]=u;
			q.push(tmp);
			siz++;
		}
	}
	while(!q.empty())q.pop();
	rstep[y]=1;rlast[y]=-1;
	q.push(y);siz++;
	while(!q.empty()&&siz<=200000)
	{
		int u=q.front();q.pop();
		if(!rstep[(u+1)%p])
		{
			rstep[(u+1)%p]=rstep[u]+1;
			rlast[(u+1)%p]=u;
			q.push((u+1)%p);
			siz++;
		}
		if(!rstep[(u+p-1)%p])
		{
			rstep[(u+p-1)%p]=rstep[u]+1;
			rlast[(u+p-1)%p]=u;
			q.push((u+p-1)%p);
			siz++;
		}
		tmp=inv(u);
		if(!rstep[tmp])
		{
			rstep[tmp]=rstep[u]+1;
			rlast[tmp]=u;
			q.push(tmp);
			siz++;
		}
	}
	while(!q.empty())q.pop();
	int top=0;
	for(auto w:last)
	{
//		cout<<w.first<<' '<<w.second<<' '<<getop(w.second,w.first)<<endl;
		arr[++top]=make_pair(w.first,0);
	}
	for(auto w:rlast)
	{
//		cout<<w.first<<' '<<w.second<<' '<<getop(w.first,w.second)<<endl;
		arr[++top]=make_pair(w.first,1);
	}
	sort(arr+1,arr+top+1);
	for(int i=1;i<top;i++)
	{
//		cout<<arr[i].first<<' '<<arr[i].second<<' '<<arr[i+1].first<<' '<<arr[i+1].second<<endl;
		if(arr[i].second!=arr[i+1].second&&arr[i].first+100>=arr[i+1].first)
		{
			if(arr[i].second==0)
			{
				int u=arr[i].first;
				while(last[u]!=-1)ord[++otop]=getop(last[u],u),u=last[u];
				while(otop)ans.push_back(ord[otop--]);
				u=arr[i].first;
				while(u!=arr[i+1].first)ans.push_back(1),u++;
				while(rlast[u]!=-1)ans.push_back(getop(u,rlast[u])),u=rlast[u];
			}
			else
			{
				int u=arr[i+1].first;
				while(last[u]!=-1)ord[++otop]=getop(last[u],u),u=last[u];
				while(otop)ans.push_back(ord[otop--]);
				u=arr[i+1].first;
				while(u!=arr[i].first)ans.push_back(2),u--;
				while(rlast[u]!=-1)ans.push_back(getop(u,rlast[u])),u=rlast[u];
			}
			printf("%d\n",ans.size());
			for(auto w:ans)printf("%d ",w);
			return 0;
		}
	}
	return 0;
}