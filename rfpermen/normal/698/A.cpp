#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int n,a[105],cnt,stat;
int main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n){
		if(!a[i])cnt++, stat=0;
		else if(a[i]==1 && stat==1)cnt++, stat=0;
		else if(a[i]==1)stat=1;
		else if(a[i]==2 && stat==2)cnt++, stat=0;
		else if(a[i]==2)stat=2;
		else if(a[i]==3 && stat==2)stat=1;
		else if(a[i]==3 && stat==1)stat=2;
	}
	cout<<cnt<<endl;
	return 0;
}