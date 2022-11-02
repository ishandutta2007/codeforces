#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
int st[20][300005],lg[300005],a[300005],b[300005];
map <pair<int,long long>,long long> mp;
inline int query(int l,int r)
{
	int X=lg[r-l+1];
	if(b[st[X][l]]<b[st[X][r-(1<<X)+1]]) return st[X][l];
	return st[X][r-(1<<X)+1];
}
const long long inf=1e17;
inline long long solve(int l,int r,int qz,int hz)
{
//	cout << l << " " << r << "\n"; 
	if(l>r) return 0;
	if(mp[{l,r+inf*qz+inf*2*hz}]) return mp[{l,r+inf*qz+inf*2*hz}]-inf;
	if(l==r)
	{
		if(!qz&&!hz)
		{
			mp[{l,r+inf*qz+inf*2*hz}]=a[l]+inf;
			return a[l];
		}
		mp[{l,r+inf*qz+inf*2*hz}]=max((int)0,a[l])+inf;
		return max((int)0,a[l]);
	}
	int pos=query(l,r);
	long long rtn=solve(l,pos-1,qz,1)+a[pos]+solve(pos+1,r,1,hz);
	if(qz) rtn=max(rtn,solve(pos+1,r,1,hz));
	if(hz) rtn=max(rtn,solve(l,pos-1,qz,1));
	if(qz&&hz) rtn=max(rtn,(long long)0);
	mp[{l,r+inf*qz+inf*2*hz}]=rtn+inf;
	return rtn;
}
signed main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) st[0][i]=i;
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			if(b[st[i-1][j]]<b[st[i-1][j+(1<<i-1)]]) st[i][j]=st[i-1][j];
			else st[i][j]=st[i-1][j+(1<<i-1)];
		}
	}
	cout << solve(1,n,0,0);
	return 0;
}