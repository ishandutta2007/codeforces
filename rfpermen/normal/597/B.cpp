#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
pair<long long,long long>x[500001];
long long a,b,idx;
int main(){
	cin>>a;
	rep(i,a)cin>>x[i].second>>x[i].first;
	sort(x,x+a);
	//rep(i,a)cout<<x[i].second<<" "<<x[i].first<<endl;
	b=x[0].first, idx=1;
	rep(i,a){
		if(b<x[i].second)idx++,b=x[i].first;
	}
	cout<<idx<<endl;
	return 0;
}