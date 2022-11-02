#include <iostream>
using namespace std;
int cnt[200],p[200005],S[200005];
string s,t;
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m >> s >> t;
	int now=0;
	for(int i=0;i<m;i++)
	{
		while(s[now]!=t[i]) now++;
		--cnt[t[i]],p[i]=now,++now;
	}
	for(int i='a';i<='z';i++) cnt[i]=0;
	now=n-1;
	for(int i=m-1;i>=0;i--)
	{
		while(s[now]!=t[i]) now--;
		--cnt[t[i]],S[i]=now,--now;
	}
	int ans=0;
	for(int i=1;i<m;i++) ans=max(ans,S[i]-p[i-1]);
	cout << ans;
	return 0;
}////////