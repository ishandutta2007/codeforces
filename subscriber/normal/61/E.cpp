#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int n,a[1111111],s[1111111],l[1111111];
long long ans=0;
pair<int,int> q[1111111];

int find(int x){
	int r=0;
	while (x){
		r+=s[x];
		x&=x-1;
	}
	return r;
}

void add(int x){
	while (x<=n){
		s[x]++;
		x=x+x-(x&(x-1));
	}
}


int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&q[i].first);
	for (int i=0;i<n;i++)q[i].second=i;
	sort(q,q+n);
	for (int i=0;i<n;i++)q[i].first=i+1;
	for (int i=0;i<n;i++)swap(q[i].first,q[i].second);
	sort(q,q+n);
	for (int i=0;i<n;i++)a[i]=q[i].second;
	for (int i=0;i<n;i++){
		l[i]=find(n)-find(a[i]);
		add(a[i]);
	}
	memset(s,0,sizeof(s));
	for (int i=n-1;i>=0;i--){
		ans+=l[i]*1ll*find(a[i]);
		add(a[i]);
	}
	cout << ans << endl;
	return 0;
}