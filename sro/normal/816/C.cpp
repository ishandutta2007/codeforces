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
int g[105][105],gg[105][105];
vector<pair<int,int> > ans1,ans2;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",g[i]+j);
			gg[i][j]=g[i][j];
		}
	}
	int sum1=0,sum2=0;
	//First kill rows, then kill columes.
	for(int i=1;i<=n;i++){
		int minx=Inf;
		for(int j=1;j<=m;j++){
			minx=min(minx,g[i][j]);
		}
		for(int j=1;j<=m;j++){
			g[i][j]-=minx;
		}
		sum1+=minx;
		ans1.push_back(make_pair(i,minx));
	}
	for(int i=1;i<=m;i++){
		int minx=Inf;
		for(int j=1;j<=n;j++){
			minx=min(minx,g[j][i]);
		}
		for(int j=1;j<=n;j++){
			g[j][i]-=minx;
		}
		sum1+=minx;
		ans1.push_back(make_pair(-i,minx));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]){
				sum1=Inf;
			}
		}
	}
	//Reversed.
	for(int i=1;i<=m;i++){
		int minx=Inf;
		for(int j=1;j<=n;j++){
			minx=min(minx,gg[j][i]);
		}
		for(int j=1;j<=n;j++){
			gg[j][i]-=minx;
		}
		sum2+=minx;
		ans2.push_back(make_pair(-i,minx));
	}
	for(int i=1;i<=n;i++){
		int minx=Inf;
		for(int j=1;j<=m;j++){
			minx=min(minx,gg[i][j]);
		}
		for(int j=1;j<=m;j++){
			gg[i][j]-=minx;
		}
		sum2+=minx;
		ans2.push_back(make_pair(i,minx));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(gg[i][j]){
				sum2=Inf;
			}
		}
	}
	if(sum1==Inf&&sum2==Inf){
		puts("-1");
		return 0;
	}
	if(sum2<sum1){
		ans1=ans2;
		sum1=sum2;
	}
	printf("%d\n",sum1);
	for(int i=0;i<SZ(ans1);i++){
		if(ans1[i].first<0){
			for(int j=0;j<ans1[i].second;j++){
				printf("col %d\n",-ans1[i].first);
			}
		}else{
			for(int j=0;j<ans1[i].second;j++){
				printf("row %d\n",ans1[i].first);
			}
		}
	}
	return 0;
}