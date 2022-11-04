#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> xp[200100];
int d,n,m;
int q[200100],qh,qt;
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&xp[i].first,&xp[i].second);
	}
	sort(xp+1,xp+m+1);
	xp[m+1].first=d;
	int npos=n;
	qh=1,qt=0;
	long long ans=0;
	for(int i=1;i<=m+1;++i){
		while(npos<xp[i].first){
			while(qh<=qt&&npos>=xp[q[qh]].first+n) ++qh;
			if(qh>qt){
				cout<<-1<<endl;
				return 0;
			}
			int mov=min(xp[q[qh]].first+n,xp[i].first);
			ans+=(long long)(mov-npos)*xp[q[qh]].second;
			npos=mov;
		}
		int f=xp[i].second;
		while(qt>=qh&&xp[q[qt]].second>=f) --qt;
		q[++qt]=i;
	}
	cout<<ans<<endl;
	return 0;
}