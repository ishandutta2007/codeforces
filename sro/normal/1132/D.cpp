#include <bits/stdc++.h>
using namespace std;

int n,k;
long long a[200005],b[200005];
int mn[200005];

bool check(long long m){
	memset(mn,0,sizeof(mn));
	for(int i=1;i<=n;i++){
		long long ch=a[i];
		if(ch/b[i]<k-1&&m==0){
			return 0;
		}
		while(ch/b[i]<k-1){
			mn[ch/b[i]]++;
			ch+=m;
		}
	}
	for(int j=k;j>=0;j--){
		mn[j]+=max(0,mn[j+1]-1);
		if(mn[j]>j+1){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long l=-1,r=1e18;
	while(r-l>1){
		long long m=(l+r)>>1;
		if(check(m)){
			r=m;
		}else{
			l=m;
		}
	}
	if(r==1e18){
		cout<<-1<<endl;
		return 0;
	}
	cout<<r<<endl;
	return 0;
}