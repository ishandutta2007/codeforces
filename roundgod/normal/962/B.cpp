#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
string str;
vector<int> st;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	cin>>str;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='.') cnt++;
		else
		{
			if(cnt>0) {st.push_back(cnt); cnt=0;}
		}
	}
	if(cnt>0) {st.push_back(cnt); cnt=0;}
	sort(st.begin(),st.end());
	int ans=0;
	for(int i=st.size()-1;i>=0;i--)
	{
		if(a<b) swap(a,b);
		int res=min((st[i]+1)/2,a)+min((st[i]/2),b);
		ans+=res;
		b-=min((st[i]/2),b);
		a-=min((st[i]+1)/2,a); 
	}
	printf("%d\n",ans);
	return 0;
}