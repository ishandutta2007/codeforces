#include <iostream>
using namespace std;
inline void solve(int l,int r,int pos)
{
	if(l==r)
	{
		cout << "! " << l << endl;
		return;
	}
	if(!pos)
	{
		cout << "? " << l << " " << r << endl;
		cin >> pos;
		solve(l,r,pos);
		return ;
	}
	if(r-l==1)
	{
		if(pos==l) cout << "! " << r << endl;
		else cout << "! " << l << endl;
		return ;
	}
	int mid=(l+r+r)/3;
	if(pos<=mid)
	{
		if(mid==l) ++mid;
		cout << "? " << l << " " << mid << endl;
		int x;
		cin >> x;
		if(x==pos) solve(l,mid,pos);
		else solve(mid+1,r,0);
	}
	else
	{
		mid=(l+l+r)/3;
		if(mid+1==r) --mid;
		cout << "? " << mid+1 << " " << r << endl;
		int x;
		cin >> x;
		if(x==pos) solve(mid+1,r,pos);
		else solve(l,mid,0);
	}
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	solve(1,n,0);
	return 0;
}