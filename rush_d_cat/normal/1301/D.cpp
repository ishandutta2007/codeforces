#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector< pair<int,char> > vec; 
int main() {
	cin>>n>>m>>k;
	int tot=n*m*4-2*n-2*m;
	if(tot<k) return !printf("NO\n");
	printf("YES\n");
	int rem = k;
	for(int i=1;i<=n;i++){
		vec.push_back(make_pair(min(m-1,rem),'R')); rem -= min(m-1,rem); if(rem==0) break;
		if(i<n) {vec.push_back(make_pair(min(m-1,rem),'L')); rem -= min(m-1,rem);} if(rem==0) break;
		if(i<n) {vec.push_back(make_pair(min(1,rem),'D')); rem -= min(1,rem);} if(rem==0) break;
	}
	for(int i=m;i>=1;i--){
		vec.push_back(make_pair(min(n-1,rem),'U')); rem -= min(n-1,rem); if(rem==0)  break;
		if(i>1) {vec.push_back(make_pair(min(n-1,rem),'D')); rem -= min(n-1,rem);} if(rem==0) break;
		if(i>1) {vec.push_back(make_pair(min(1,rem),'L'));rem-=min(1,rem);} if(rem==0)  break;
	}
	vector< pair<int,char> > vec2;
	for(auto p: vec) {
		if(p.first) vec2.push_back(p);
	} 
	vec = vec2;
	printf("%d\n", (int)vec.size());
	for(auto p: vec) {
		printf("%d %c\n", p.first,p.second);
	}
}
/*
2n + 2m
*/