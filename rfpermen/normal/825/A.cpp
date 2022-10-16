#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=1005;
string s;
int cnt;
int main(){
	cin>>cnt;
	cin>>s;
	cnt=0;
	rep(i,0,s.size()-1){
		if(s[i]=='1')cnt++;
		else cout<<cnt, cnt=0;
	}
	cout<<cnt;
	cout<<endl;
	return 0;
}