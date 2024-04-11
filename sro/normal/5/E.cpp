#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000005];
int l[2000005],r[2000005];
map<int,int> idx;
vector<int> lst[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i+n]=a[i];
		if(!idx[a[i]]){
			idx[a[i]]=++cnt;
		}
		lst[idx[a[i]]].push_back(i);
	}
	for(int i=1;i<=cnt;i++){
		int len=lst[i].size();
		for(int j=0;j<len;j++){
			lst[i].push_back(lst[i][j]+n);
		}
	}
	for(int i=0;i<2*n;i++){
		l[i]=i-1;
		while(l[i]>=0&&a[i]>=a[l[i]]){
			l[i]=l[l[i]];
		}
	}
	for(int i=2*n-1;i>=0;i--){
		r[i]=i+1;
		while(r[i]<2*n&&a[i]>=a[r[i]]){
			r[i]=r[r[i]];
		}
	}
	long long ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		if(r[i]==2*n){
			ans2+=lst[idx[a[i]]].size()/2-1;
		}else{
			if(l[n+i]>=n){
				l[n+i]-=n;
			}
			if(r[i]>=n){
				r[i]-=n;
			}
			if(l[n+i]==r[i]){
				ans1++;
				ans2+=lst[idx[a[i]]].size()/2-1;
			}else{
				ans1+=2;
				if(l[n+i]>i){
					r[i]+=n;
				}else if(r[i]<i){
					r[i]+=n;
				}
				int ind=idx[a[i]];
				ans2+=lower_bound(lst[ind].begin(),lst[ind].end(),r[i])-lower_bound(lst[ind].begin(),lst[ind].end(),l[n+i])-1;
			}
		}
	}
	cout<<ans1+ans2/2<<endl;
	return 0;
}