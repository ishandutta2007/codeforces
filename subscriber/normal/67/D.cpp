#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int n,x,w[1111111],a[1111111],f[1111111],s[1111111],d[1111111],ans=0;

void add(int x,int v){
	while (x<=n){
		if (v>s[x])s[x]=v;
		x=x+x-(x&(x-1));
	}
}

int find(int x){
	int r=0;
	while (x){
		if (s[x]>r)r=s[x];
		x&=x-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		w[x]=i;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		a[i]=w[x]+1;
	}
	for (int i=n-1;i>=0;i--){
		x=find(a[i]);
		f[i]=x+1;
		ans=max(ans,f[i]);
		add(a[i],f[i]);
	}
	cout << ans << endl;
	return 0;
}