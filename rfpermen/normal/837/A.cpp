#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
int n,cnt,mx;
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	//ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	cin.ignore();
	getline(cin,s);
	rep(i,0,s.size()-1){
		if(s[i]==' '){
			if(cnt>mx)mx=cnt;
			cnt=0;
		}
		else if(s[i]<95)cnt++;
	}if(cnt>mx)mx=cnt;
	cout<<mx<<endl;
	return 0;
}