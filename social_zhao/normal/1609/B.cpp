#include<bits/stdc++.h>
//#define int long long
const int N=100500;
using namespace std;

string s;
int n,q;

bool chk(int k){
	if(k<0||k>n-3)return 0;
	return s[k]=='a'&&s[k+1]=='b'&&s[k+2]=='c';
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	cin>>s;
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=chk(i);
	for(int i=1;i<=q;i++){
		int x;char y;cin>>x>>y;x--;
		int na=0;
		na-=chk(x),na-=chk(x-1),na-=chk(x-2);
		swap(s[x],y);
		na+=chk(x),na+=chk(x-1),na+=chk(x-2);
		cout<<ans+na<<endl;
	//	swap(a[x],y);
		ans+=na;
	}
}