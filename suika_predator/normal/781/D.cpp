#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<bitset>
using namespace std;
const int MAXN=501;
int siz;
struct matrix {
	bitset<501> mat[MAXN];
	inline matrix(){for(int i=1;i<=siz;i++)mat[i]=0;}
	inline matrix operator=(const matrix &m)
	{
		for(int i=1;i<=siz;i++)
		{
			mat[i]=m.mat[i];
		}
		return *this;
    }
    inline matrix transpose(const matrix &m)const
    {
    	matrix tmp;
    	for(int i=1;i<=siz;i++)
    	{
    		for(int j=1;j<=siz;j++)
    		{
    			tmp.mat[j][i]=m.mat[i][j];
			}
		}
		return tmp;
	}
	inline matrix operator*(const matrix &m)const
	{
		matrix tmp,tr=transpose(m);
		for(int i=1;i<=siz;i++)
		{
			for(int j=1;j<=siz;j++)
			{
				tmp.mat[i][j]=(mat[i]&tr.mat[j]).any();
			}
		}
		return tmp;
	}
	inline matrix operator*=(const matrix &m)
	{
		return *this=*this*m;
	}
	inline bool operator!=(const matrix &m)const
	{
		for(int i=1;i<=siz;i++)
		{
			if(mat[i]!=m.mat[i])return true;
		}
		return false;
	}
}table[63][2],empty;//0:first=p,1:first=b;
int n,m;
int main()
{
	//freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	siz=n;
	int a,b,type;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&type);
		table[0][type].mat[a][b]=1;
	}
	/*for(int x=1;x<=siz;x++)
	{
		for(int y=1;y<=siz;y++)
		{
			cout<<table[0][0].mat[x][y]<<' ';
		}
		cout<<endl;
	}
	for(int x=1;x<=siz;x++)
	{
		for(int y=1;y<=siz;y++)
		{
			cout<<table[0][1].mat[x][y]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;*/
	for(int i=1;i<=60;i++)
	{
		table[i][0]=table[i-1][0]*table[i-1][1];
		table[i][1]=table[i-1][1]*table[i-1][0];
		/*for(int x=1;x<=siz;x++)
		{
			for(int y=1;y<=siz;y++)
			{
				cout<<table[i][0].mat[x][y]<<' ';
			}
			cout<<endl;
		}
		for(int x=1;x<=siz;x++)
		{
			for(int y=1;y<=siz;y++)
			{
				cout<<table[i][1].mat[x][y]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	long long l=0;
	bool next=0;
	matrix cur;
	cur.mat[1][1]=1;
	for(int bit=60;~bit;--bit)
	{
		matrix tmp=cur*table[bit][next];
		if(tmp!=empty)
		{
			cur=tmp;
			l+=1ll<<bit;
			next^=1;
		}
		/*cout<<bit<<endl;
		for(int i=1;i<=siz;i++)
		{
			for(int j=1;j<=siz;j++)
			{
				cout<<cur.mat[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<bit<<endl;
		for(int i=1;i<=siz;i++)
		{
			for(int j=1;j<=siz;j++)
			{
				cout<<tmp.mat[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	if(l>1000000000000000000ll)l=-1;
	printf("%I64d\n",l);
	return 0;
}