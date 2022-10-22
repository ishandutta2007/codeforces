#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
int n,k;
const int N=100010;
bool bad[N][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	vector<int>x(k);
	for(int i=0;i<k;++i){
		cin>>x[i];
	}
	set<int>st;
	for(int i=k-1;i>=0;--i){
		int kek=x[i];
		if(st.count(kek+1))bad[kek][0]=true;
		if(st.count(kek-1))bad[kek][1]=true;
		bad[kek][2]=true;
		st.insert(kek);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(i+1<=n&&!bad[i][0])++ans;
		if(i-1>=1&&!bad[i][1])++ans;
		if(!bad[i][2])++ans;
	}
	cout<<ans<<'\n';
	return 0;
}