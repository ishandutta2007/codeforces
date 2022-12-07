#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int me[110000];
int main()
{
	int n,x,y,i,j;
	memset(me,0,sizeof(me));
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d %d",&x,&y);int ret=0;
		for(j=1;j*j<=x;j++){
			if(x%j!=0) continue;
			if(me[j]<i-y) ret++;me[j]=i;
			if(j*j<x){
				if(me[x/j]<i-y) ret++;me[x/j]=i;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}