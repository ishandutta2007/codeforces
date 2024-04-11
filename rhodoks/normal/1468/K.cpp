#include <bits/stdc++.h>

using namespace std;

string s;
typedef pair<int,int> pii;
int dir[256][2];
vector<pii> v;
int bx,by;
void work()
{
	cin>>s;
	v.clear();
	int posx=0,posy=0;
	for (auto p:s)
	{
		posx+=dir[p][0];
		posy+=dir[p][1];
		if (posx || posy)
			v.push_back({posx,posy});
	}
	for (auto q:v)
	{
		bx=q.first;
		by=q.second;
		posx=0;
		posy=0;
		for (auto p:s)
		{
			if (posx+dir[p][0]==bx && posy+dir[p][1]==by)
				continue;
			posx+=dir[p][0];
			posy+=dir[p][1];
		}
		if (posx==0 && posy==0)
		{
			cout<<bx<<' '<<by<<endl;
			return;
		}
	}
	cout<<0<<' '<<0<<endl;
}

int main()
{
	dir['U'][0]=0;
	dir['U'][1]=1;
	dir['D'][0]=0;
	dir['D'][1]=-1;
	dir['L'][0]=-1;
	dir['L'][1]=0;
	dir['R'][0]=1;
	dir['R'][1]=0;
	int t;
	cin>>t;
	while (t--)
		work();
	return 0;
}