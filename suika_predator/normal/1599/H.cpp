#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N=1e9;
	int len1,len2;
	cout<<"? "<<1<<' '<<1<<endl;
	cin>>len1;
	cout<<"? "<<1<<' '<<N<<endl;
	cin>>len2;
	int Lx=len1+1,Rx=N-len2;
	int midx=(Lx+Rx)/2;
	cout<<"? "<<1<<' '<<midx<<endl;
	int y;
	cin>>y;
	int Ly=y+1;
	cout<<"? "<<N<<' '<<midx<<endl;
	cin>>y;
	int Ry=N-y;
	cout<<"! "<<Ly<<' '<<(len1+2-Ly)<<' '<<Ry<<' '<<(N+Ly-1-len2)<<endl;
	return 0;
}