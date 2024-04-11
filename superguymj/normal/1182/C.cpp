#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair

using namespace std;
const int N=100005;
int n;
string s[N];
const char S[]={'a','i','u','e','o'};
vector <int> vt[1000005][6],vt2[1000005];
vector <pair <int,int> > A,B;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) cin>>s[i];
	rep(i,1,n)
	{
		int len=s[i].length(),x=-1,cnt=0;
		rep(j,0,len-1) rep(k,0,4) if(s[i][j]==S[k]) ++cnt,x=k;
		if(cnt) vt[cnt][x].pb(i);
	}
	rep(i,1,1000000)
	{
		rep(j,0,4)
		{
			while(vt[i][j].size()>=2)
			{
				int sz=vt[i][j].size()-1;
				A.pb(mp(vt[i][j][sz-1],vt[i][j][sz]));
				vt[i][j].pop_back();
				vt[i][j].pop_back();
			}
			if(vt[i][j].size()==1) vt2[i].pb(vt[i][j][0]);
		}
		while(vt2[i].size()>=2)
		{
			int sz=vt2[i].size()-1;
			B.pb(mp(vt2[i][sz-1],vt2[i][sz]));
			vt2[i].pop_back();
			vt2[i].pop_back();
		}
	}
	int ans=min((int)A.size(),((int)A.size()+(int)B.size())>>1);
	printf("%d\n",ans);
	int szA=A.size(),szB=B.size();
	rep(i,1,min((int)B.size(),ans))
	{
		int x=B[i-1].first,y=A[i-1].first;
		cout<<s[x]<<' '<<s[y]<<endl;
		x=B[i-1].second,y=A[i-1].second;
		cout<<s[x]<<' '<<s[y]<<endl;
	}
	int tmp=min((int)B.size(),ans);
	ans-=min((int)B.size(),ans);
	rep(i,1,ans)
	{
		int x=A[tmp].first,y=A[tmp+1].first;
		cout<<s[x]<<' '<<s[y]<<endl;
		x=A[tmp].second,y=A[tmp+1].second;
		cout<<s[x]<<' '<<s[y]<<endl;
		tmp+=2;
	}
	return 0;
}