#include<cstdio>
#include<algorithm>
#include<string>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 3005, MY = 10005, INF = 1000000000;

int c[5];

int main(){
	int n, a;
	scanf("%d",&n);
	
	rep(i,n){
		scanf("%d",&a);
		c[a]++;
	}
	
	c[1] = max(c[1]-c[3],0);
	c[4] += c[2]/2;
	if(c[2]&1){ c[4]++; c[1] = max(c[1]-2,0);}
	
	printf("%d\n",c[4]+c[3]+(c[1]+3)/4);
	
	return 0;
}