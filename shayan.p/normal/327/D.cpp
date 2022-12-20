#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll out(ll x) {printf("%ld ",x);};
inline ll in() {ll x; scanf("%ld", &x); return x;};
class LISS
{
	ll ans=0;
	char a[1000010];
	ll b[1000010],c[1000010];
	public:
	void P(char x,ll y,ll z)
	{
		a[ans]=x;
		b[ans]=y;
		c[ans]=z;
		ans++;
	}
	void tell()
	{
		printf("%ld \n",ans);
		for(ll i=0;i<ans;i++)
		{
		printf("%c ",a[i]);
		printf("%ld ",b[i]);
		printf("%ld ",c[i]);
		printf("\n");
		}
	}
};
LISS LIST;
const ll N=1000;
ll n,m;
char ch[N][N];
bool pos(ll a,ll b)
{
	if(a>=0&&a<n&&b>=0&&b<m)
	{
		if(ch[a][b]=='.')
		return 1;
	}
	return 0;
}
inline void print(ll a,ll b)
{
	LIST.P('B',a+1,b+1);
	ch[a][b]='B';
}
void dfs(ll a,ll b,bool check)
{
	if(check)
	print(a,b);
	ll i,j;
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
			if((j==0||i==0)&&!(j==0&&i==0)){
				if(pos(a+i,b+j)){
					print(a+i,b+j);
					dfs(a+i,b+j,0);
				}
			}
	if(!check){
	LIST.P('D',a+1,b+1);
	LIST.P('R',a+1,b+1);
	}
}
void get_in()
{
	ll i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		cin>>ch[i][j];
}
int main()
{
	get_in();
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			if(pos(i,j))
			dfs(i,j,1);
			LIST.tell();
}