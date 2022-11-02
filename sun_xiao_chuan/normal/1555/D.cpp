#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
int f[200500][7];
char s[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t>>s+1;
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][1]+=(s[i]!='a');
		}
		if((i%3)==1){
			f[i][1]+=(s[i]!='b');
		}
		if((i%3)==2){
			f[i][1]+=(s[i]!='c');
		}
	}
	
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][2]+=(s[i]!='a');
		}
		if((i%3)==1){
			f[i][2]+=(s[i]!='c');
		}
		if((i%3)==2){
			f[i][2]+=(s[i]!='b');
		}
	}
	
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][3]+=(s[i]!='b');
		}
		if((i%3)==1){
			f[i][3]+=(s[i]!='a');
		}
		if((i%3)==2){
			f[i][3]+=(s[i]!='c');
		}
	}
	
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][4]+=(s[i]!='b');
		}
		if((i%3)==1){
			f[i][4]+=(s[i]!='c');
		}
		if((i%3)==2){
			f[i][4]+=(s[i]!='a');
		}
	}
	
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][5]+=(s[i]!='c');
		}
		if((i%3)==1){
			f[i][5]+=(s[i]!='a');
		}
		if((i%3)==2){
			f[i][5]+=(s[i]!='b');
		}
	}
	
	for(i=1;i<=n;i++){
		if((i%3)==0){
			f[i][6]+=(s[i]!='c');
		}
		if((i%3)==1){
			f[i][6]+=(s[i]!='b');
		}
		if((i%3)==2){
			f[i][6]+=(s[i]!='a');
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=6;j++){
			f[i][j]+=f[i-1][j];
		}
	}
	
	while(t--){
		int res=1e9,l,r;
		cin>>l>>r;
		for(i=1;i<=6;i++){
			res=min(res,f[r][i]-f[l-1][i]);
		}
		cout<<res<<endl;
	}
}