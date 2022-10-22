#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=5050;
const int MX=50050;
int a[N];
int n, m;

int calc(){
	static bool ex[MX];
	fill(ex,ex+MX,0);
	for(int i=0;i<n;++i)
		ex[a[i]]=true;
	int ans=0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if (ex[a[i]+a[j]])++ans;
	if (ans==m){
		for(int i=0;i<n;++i)
			cout<<a[i]<<' ';
		cout<<'\n';
		exit(0);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	 mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
	n=1+rnd()%5000;
	m=rnd()%(n*n/4+1);
	cin>>n>>m;
//	cerr<<n<<' '<<m<<'\n';
	for(int i=0;i<n;++i)
		a[i]=i+1;
	if(calc()<m){
		 cout<<-1<<'\n';
		 return 0;
	}
	int L=1,R=n+2;
	while(R-L>1){
		int M=(L+R)/2;
		for(int i=0;i<n;++i)
			a[i]=i+M;
		if(calc()>m)
			L=M;
		else
			R=M;
	}
	for(int i=0;i<n;++i)
		a[i]=i+L;
	int cur=n-1;
	int c=calc();
	int ptr=0;
	a[cur]+=1000;
	if(calc()<m||calc()>c)
		a[cur]-=1000;
	while(true){
		if (cur!=n-1&&a[cur]+1==a[cur+1])--cur;
		int d;
		if (c-m>10&&(cur == n - 1 || a[cur] + (c-m)*3/4 < a[cur+1])){
			a[cur]+=(c-m)*3/4;
			d=calc();
			if (d<m){
				a[cur]-=(c-m)*3/4;
				a[cur]++;
				d=calc();
			}
		}
		else
			++a[cur],d=calc();
		if (c==d){
			if(++ptr==30){
				--cur,ptr=0;
				a[cur]+=1000;
				if (a[cur]>=a[cur+1]||calc()<m||calc()>c)
					a[cur]-=1000;
			}
		}
		c=d;
	}
	assert(false);
	return 0;
}