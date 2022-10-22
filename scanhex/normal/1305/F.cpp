#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())
const int N=200200;
nagai a[N];

mt19937 rnd(1234);

int n;
nagai mn=1e9;
set<nagai>checked;
void check(nagai x){
	if (checked.count(x))
		return;
	checked.insert(x);
	nagai ansich=0;
	for(int i=0;i<n;++i){
		 nagai kek=a[i]%x;
		 if (a[i] < x)
			 ansich+=x-kek;
		 else
			 ansich+=min(kek,x-kek);
	}
	mn=min(mn,ansich);
}

vector<nagai> fact(nagai x){
	vector<nagai>ans;
	for(nagai i=2;i*i<x;++i)
		if(x%i==0){
			ans.push_back(i);
			while(x%i==0)x/=i;
		}
	if (x>1)
		ans.push_back(x);
	return ans;
}

nagai xtime(){
	return clock()*1000/CLOCKS_PER_SEC;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai t=xtime();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=2;i<4;++i)
		check(i);
	while(xtime()-t<1900){
		int x=rnd()%n;
		for(nagai j=a[x]-5;j<a[x]+5;++j){
			for(nagai x:fact(j)){
				check(x);
			}
		}
	}
	cout<<mn<<'\n';
	return 0;
}