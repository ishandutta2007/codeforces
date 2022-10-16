#include<bits/stdc++.h>
using namespace std;
vector<int> XandY,XXX,YYY;
int NOseg;
int query(int x,int y)
{
	cout<<0<<" "<<x<<" "<<y<<endl;
	int ret;cin>>ret;return ret;
}
void SOLVE(int l,int r)
{
	if (l>r) return;
	int mid=(l+r)/2;
	int x=query(mid,mid);
	if(x==0) XandY.push_back(mid),x=1;else NOseg=mid;
	SOLVE(l,mid-x);SOLVE(mid+x,r);
}
void solve()
{
	SOLVE(-100000000,100000000);
	for (int k:XandY)
	{
		if (query(NOseg,k)==0) YYY.push_back(k);
		if (query(k,NOseg)==0) XXX.push_back(k);
	}
}
int main()
{
	solve();
	cout<<"1 "<<XXX.size()<<" "<<YYY.size()<<endl;
	for (int x:XXX) cout<<x<<" ";cout<<endl;
	for (int y:YYY) cout<<y<<" ";cout<<endl;
}