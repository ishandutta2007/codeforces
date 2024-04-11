#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
string str;
vector<int> occ[26];
int res[26];
int main()
{
	cin>>str;
	int l=str.size();
	for(int i=0;i<l;i++)
		occ[str[i]-'a'].push_back(i);
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		int num=0;
		if(occ[i].size()==0) continue;
		for(int j=0;j<l;j++)
		{
			int cnt2=0;
			memset(res,0,sizeof(res));
			for(int k=0;k<occ[i].size();k++)
				res[str[(occ[i][k]+j)%l]-'a']++;
			for(int k=0;k<26;k++)
				if(res[k]==1) cnt2++;
			num=max(num,cnt2);
		}
		cnt+=num;
	}
	printf("%.10f\n",(double)cnt/l);
	return 0;
}