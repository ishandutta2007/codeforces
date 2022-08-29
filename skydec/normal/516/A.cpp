#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int num[11];char a[19];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",a+1);	
	rep(i,1,n){
		int x=a[i]-'0';
		if(x==4){num[2]+=2;num[3]++;}
		else if(x==6){num[5]++;num[3]++;}
		else if(x==8){num[7]++;num[2]+=3;}
		else if(x==9){num[7]++;num[2]++;num[3]+=2;}
		else num[x]++;
	}
	per(i,9,2)rep(j,1,num[i])printf("%d",i);
	return 0;
}