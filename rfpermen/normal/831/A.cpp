#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define fi first
#define se second
int n,stat,last,ans,tmp;
int main(){
	cin>>n;
	cin>>last;
	ans=1, stat=1;
	rep(i,2,n){
		cin>>tmp;
		if(tmp>last && stat==-1)ans=0;
		else if(tmp==last && stat==-1)ans=0;
		else if(tmp==last && stat==1)stat=0;
		else if(tmp>last && stat==0)ans=0;
		else if(tmp==last && stat==1)stat=0;
		else if(tmp<last && (stat==0 || stat==1))stat=-1;
		last=tmp;
	}
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}