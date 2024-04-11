#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#define M 1000000007

using namespace std;

int l,n,f[111111],s[111111],ans=0,x,y;
pair<int,int>q[111111];


void add(int x,int v){
	x++;
	while (x<=n+1){
		s[x]=(s[x]+v)%M;
		x=x+x-(x&(x-1));
	}
}

int find(int x){
	x++;
	int r=0;
	while (x){
		r=(r+s[x])%M;
		x&=x-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> l >> n;
	q[0]=make_pair(0,0);
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		q[i+1]=make_pair(y,x);
	}
	sort(q,q+n+1);
	f[0]=1;
	add(0,1);
	for (int i=0;i<n;i++){
		int x=lower_bound(q,q+n+1,make_pair(q[i+1].second,0))-q;
		int xx=lower_bound(q,q+n+1,make_pair(q[i+1].first,0))-q;
		int y=(find(xx-1)-find(x-1)+M)%M;
		f[i+1]=y;
		add(i+1,y);
	}
	for (int i=0;i<=n;i++)if (q[i].first==l)ans=(ans+f[i])%M;
	cout << ans << endl;
	return 0;
}