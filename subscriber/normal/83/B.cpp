#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,m,a[211111],p[211111],b[211111];
priority_queue<pair<int,int> > q;
long long k,s,e,g;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)q.push(make_pair(-a[i],i));
	for (int i=0;i<n;i++)p[i]=i;
	s=n;
	e=0;
	while (s){
		g=min(-q.top().first-e,k/s);
		if (!g)break;
		k-=s*g;
		e+=g;
		while (q.empty()==0&&-q.top().first<=e){
			q.pop();
			s--;
		}		
	}
	while (q.empty()==0){
		if (-q.top().first>e)b[q.top().second]=-q.top().first-e;	
		q.pop();
	}
	for (int i=0;i<n;i++)if (k&&b[i]){
		p[n]=i;
		b[n++]=b[i]-1;
		b[i]=0;
		k--;
	}
	if (k){
		puts("-1");
		return 0;
	}
	int t=0;
	for (int i=0;i<n;i++)if (b[i]){
		if (t)putchar(' ');
		t=1;
		printf("%d",p[i]+1);
	}
	puts("");
	return 0;
}