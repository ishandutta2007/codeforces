#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
#include<queue>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=600000;
int a[MAXN];int n;
priority_queue<LL>tmp,now;
int rest=0;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int j=i;while(j<n&&a[j+1]==a[i])j++;
		int num=j-i+1;
		for(;rest&&num;rest--,num--)tmp.push(-a[i]);
		for(;num>1&&!now.empty();num-=2){
			LL bg=-now.top();
			now.pop();
			if(a[i]<=bg){
				tmp.push(-bg);
				tmp.push(-(2ll*a[i]-bg));
			}
			else{
				tmp.push(-a[i]);tmp.push(-a[i]);
			}
		}
		if(num&&!now.empty()){
			LL bg=-now.top();//now.pop();
			if(bg<=a[i]){tmp.push(-a[i]);now.pop();}
		}
		rest+=num;
		while(!tmp.empty()){
			now.push(tmp.top());tmp.pop();
		}
		i=j;
	}
	LL sum=0;
	rep(i,1,n)sum+=1ll*a[i];
	while(!now.empty()){
		LL bg=-now.top();now.pop();
		if(bg>0)sum-=bg;
	}
	printf("%I64d\n",sum);
	return 0;
}