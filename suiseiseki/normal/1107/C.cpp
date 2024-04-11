#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
int a[Maxn+5];
vector<int> e;
char s[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n+1;i++){
		if(s[i]!=s[i-1]){
			if(!e.empty()){
				sort(e.begin(),e.end(),cmp);
				for(int j=0;j<k&&j<(int)e.size();j++){
					ans+=e[j];
				}
			}
			e.clear();
		}
		e.push_back(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}