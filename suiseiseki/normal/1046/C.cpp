#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
ll s[Maxn+5],p[Maxn+5];
int main(){
	ios::sync_with_stdio(false);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	s[d]+=p[1];
	int i=1,j=n;
	int ans=0;
	while(i<d){
		if(s[i]+p[j]<=s[d]){
			i++;
			j--;
		}
		else{
			i++;
			ans++;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}