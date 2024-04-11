#include<bits/stdc++.h>
using namespace std;
char ch[1005][1005];
int num[1005],cnt[1005],n,m,ans;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>ch[i];
	for(int i=1; i<=m; i++)cin>>num[i];
	for(int i=0; i<m; i++) {
		cnt['A']=cnt['B']=cnt['C']=cnt['D']=cnt['E']=0;
		for(int j=1; j<=n; j++)cnt[ch[j][i]]++;
		ans+=(num[i+1]*(max(max(max(max(cnt['A'],cnt['B']),cnt['C']),cnt['D']),cnt['E'])));
	}
	cout<<ans;
	return 0;
}