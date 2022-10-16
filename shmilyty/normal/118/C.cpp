#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> pis;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	string str;
	cin>>str;
	vector<vector<int> > pos(10);
	for(int i=0;i<n;i++)
		pos[str[i]-'0'].push_back(i);
	pis res=pis(114514,"");
	for(int dig=0;dig<10;dig++)
	{
		string cr=str;
		int cc=0;
		int toDo=k-(int)pos[dig].size();
		for(int i=1;toDo>0;i++)
		{
			if(dig+i<10)
				for(int j=0;j<pos[dig+i].size()&&toDo>0;j++)
				{
					cr[pos[dig+i][j]]=dig+'0';
					--toDo;
					cc+=i;
				} 
			if(dig-i>=0)
				for(int j=0;j<pos[dig-i].size()&&toDo>0;j++)
				{
					cr[pos[dig-i][pos[dig-i].size()-j-1]]=dig+'0';
					--toDo;
					cc+=i;
				}
		}
		res=min(res,pis(cc,cr));
	}
	cout<<res.first<<endl<<res.second<<endl;
	return 0;
}