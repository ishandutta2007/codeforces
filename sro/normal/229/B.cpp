//Go to http://threebody.com/ to learn more about THREEBODY.
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SZ(s) ((int)(s).size())
#define INT long long
#define Mod 1000000007
#define Inf 0x3f3f3f3f
using namespace std;
//Coded by charlieyan, all rights reserved.
/*                                               
  mmmm                       mmmm     mmm   mmmm 
 m"  "m  m mm  mmmmm         #   "m     #  m"  "m
 #    #  #"  "    m"         #    #     #  #    #
 #    #  #      m"           #    #     #  #    #
  #mm#   #     #mmmm         #mmm"  "mmm"   #mm#"
                                               # 
*/

int n,m;
vector<pair<int,int> > nei[100005];
set<int> arr[100005];
int dist[100005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		nei[a].push_back(make_pair(b,c));
		nei[b].push_back(make_pair(a,c));
	}
	for(int i=1;i<=n;i++){
		int diudc;
		scanf("%d",&diudc);
		while(diudc--){
			int ahdfe;
			scanf("%d",&ahdfe);
			arr[i].insert(ahdfe);
		}
	}
	priority_queue<pair<int,int> > pq;
	memset(dist,0x3f,sizeof(dist));
	pq.push(make_pair(0,1));
	dist[1]=0;
	while(SZ(pq)){
		pair<int,int> PQ=pq.top();
		pq.pop();
		int dis=-PQ.first,whr=PQ.second;
		while(arr[whr].count(dis)){
			dis++;
		}
		for(int i=0;i<SZ(nei[whr]);i++){
			int to=nei[whr][i].first;
			if(dist[to]>dis+nei[whr][i].second){
				dist[to]=dis+nei[whr][i].second;
				pq.push(make_pair(-dist[to],to));
			}
		}
	}
	if(dist[n]==Inf){
		puts("-1");
	}else{
		printf("%d\n",dist[n]);
	}
	return 0;
}