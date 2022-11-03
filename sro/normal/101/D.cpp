#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define SZ(s) ((int)(s).size())
typedef pair<int,int> pii;
//Coded by charlieyan, all rights reserved.

int n;
vector<pii> nei[100007];
int t[100007];
int cnt[100007];

int dfs1(int now,int lst){
	int tmuse=0;
	int Cnt=1;
	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i].first!=lst){
			tmuse+=nei[now][i].second;
			tmuse+=dfs1(nei[now][i].first,now);
			Cnt+=cnt[nei[now][i].first];
		}
	}
	cnt[now]=Cnt;
	return t[now]=tmuse;
}

bool Sort_Comp(pii a,pii b){
	return 2LL*(t[a.first]+a.second)*cnt[b.first]<2LL*(t[b.first]+b.second)*cnt[a.first];
}

int tmnow=0;
long long tmall=0;

void dfs2(int now,int lst){
	tmall+=tmnow;
	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i].first!=lst){
			tmnow+=nei[now][i].second;
			dfs2(nei[now][i].first,now);
			tmnow+=nei[now][i].second;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		nei[a].pb(mp(b,c));
		nei[b].pb(mp(a,c));
	}
	dfs1(1,-1);
	for(int i=1;i<=n;i++){
		sort(nei[i].begin(),nei[i].end(),Sort_Comp);
	}
	dfs2(1,-1);
	printf("%.15f\n",1.00*tmall/(n-1));
	return 0;
}