#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#define X pair<long long,pair<long long,long long> >

using namespace std;

long long a,t[3],s[3],o1[3],o2[3],v[3][311111],ans=0,n;
priority_queue<X,vector<X >,greater<X > > q;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s[0] >> s[1] >> s[2] >> t[0] >> t[1] >> t[2] >> n;
	for (int i=0;i<n;i++){
		cin >> a;
		q.push(make_pair(a,make_pair(-1,a)));
	}
	while (!q.empty()){
		long long tt=q.top().first;
		if (q.top().second.first>=0)s[q.top().second.first]++;
		if (q.top().second.first!=2)v[q.top().second.first+1][o1[q.top().second.first+1]++]=q.top().second.second;else
		ans=max(ans,tt-q.top().second.second);
		q.pop();
		for (int i=0;i<3;i++)
		for (int j=o2[i];j<o1[i];j++)if (!s[i])break;else{
			s[i]--;
			q.push(make_pair(tt+t[i],make_pair(i,v[i][j])));
			o2[i]++;
		}
	}
	cout << ans << endl;
	return 0;
}