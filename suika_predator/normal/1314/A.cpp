#include<bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int> w[233333];
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i].first;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>w[i].second;
	}
	w[n+1].first=0x3f3f3f3f;
	sort(w+1,w+n+1);
	long long s=0,ans=0;
	int cur=w[1].first;
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<' '<<w[i].first<<endl;
		pq.push(w[i].second);
//		cerr<<"push "<<i<<' '<<w[i].second<<endl;
		s+=w[i].second;
		while(w[i].first==w[i+1].first)
		{
			i++;
			pq.push(w[i].second);
//			cerr<<"push "<<i<<' '<<w[i].second<<endl;
			s+=w[i].second;
		}
		cur=w[i].first;
//		cerr<<i<<' '<<s<<endl;
		while(cur<w[i+1].first&&!pq.empty())
		{
//			cerr<<i<<' '<<s<<endl;
			s-=pq.top();pq.pop();
//			cerr<<"pop "<<i<<' '<<w[i].second<<endl;
			ans+=s;
			cur++;
		}
	}
	cout<<ans<<endl;
	return 0;
}