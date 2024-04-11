#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

const int N=128*128;
vector<int> V[N];
int In[N],n,x,y,S=-1;
string Ans;
char s[5];

int ID(char a,char b) {return a*128+b;}
void DFS(int x)
{
	while (V[x].size()) {int t=V[x].back();V[x].pop_back();DFS(t);}
	Ans+=x%128;
}

int main()
{
	scanf("%d",&n);
	For(i,0,n)
	{
		scanf("%s",s);
		x=ID(s[0],s[1]),y=ID(s[1],s[2]);
		V[x].Pb(y),In[y]++;
	}
	For(i,0,N) if (abs(int(V[i].size())-In[i])>1) return puts("NO"),0;
	For(i,0,N) if (V[i].size()==In[i]+1) if (~S) return puts("NO"),0;else S=i;
	if (S==-1) For(i,0,N) if (V[i].size()) S=i;
	DFS(S);Ans+=S/128;
	reverse(Ans.begin(),Ans.end());
	if (Ans.length()==n+2) puts("YES"),puts(Ans.c_str());else puts("NO");
}