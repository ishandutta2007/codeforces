#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100050,M=100050,S=2,D=20;
struct matrix
{
	long long a[S][S];
}f[D][N]={},one={{{1,0},{0,1}}},sum=one,ans=one;
void print(const matrix &m)
{
	cout<<"("<<m.a[0][0]<<","<<m.a[0][1]<<") ("<<m.a[1][0]<<","<<m.a[1][1]<<")"<<endl;
}
int n,m,s[N]={};
pair<long long,int> special[M];
pair<long long,matrix> spe_matr[M+M];
long long k,mod;
matrix operator * (const matrix &m1,const matrix &m2)
{
	matrix ans={{}};
	for(int i=0;i<S;++i)
		for(int j=0;j<S;++j)
			for(int k=0;k<S;++k)
				ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%mod;
	return ans;
}
matrix power(matrix x,long long y)
{
	matrix t=one;
	for(; y; y>>=1,x=x*x)
		if(y&1) t=t*x;
	return t;
}
void init()
{
	cin>>k>>mod;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>s[i];
	s[n]=s[0];
	cin>>m;
	for(int i=1;i<=m;++i)
		cin>>special[i].first>>special[i].second;
	sort(special+1,special+m+1);
	spe_matr[0].second=one;
	if(m==0)
		return;
	int tot=0;
	long long d=special[1].first;
	spe_matr[++tot]={d,{{{special[1].second,s[(d-1)%n]},{1,0}}}};
	for(int i=2;i<=m;++i)
	{
		long long d1=special[i].first;
		long long d2=special[i-1].first;
		if(d1==d2+1)
			spe_matr[++tot]={d1,{{{special[i].second,special[i-1].second},{1,0}}}};
		else
		{
			spe_matr[++tot]={d2+1,{{{s[(d2+1)%n],special[i-1].second},{1,0}}}};
			spe_matr[++tot]={d1,{{{special[i].second,s[(d1-1)%n]},{1,0}}}};
		}
	}
	d=special[m].first;
	spe_matr[++tot]={d+1,{{{s[(d+1)%n],special[m].second},{1,0}}}};
	m=tot;/*
	for(int i=1;i<=m;++i)
	{
		cout<<"d="<<spe_matr[i].first<<endl;
		print(spe_matr[i].second);
	}*/
}
void get_seg()
{
	for(int j=0;j<D;++j)
		for(int i=0;i<=n;++i)
			f[j][i]=one;
	for(int i=1;i<=n;++i)
		f[0][i]={{{s[i],s[i-1]},{1,0}}};
	f[0][0]=f[0][n];
	for(int j=1;j<D;++j)
		for(int i=0;i<=n-(1<<j)/2;++i)
			f[j][i]=f[j-1][i+(1<<j)/2]*f[j-1][i];
	for(int i=0;i<n;++i)
		sum=f[0][i]*sum;
	//print(sum);
}
matrix get_sum(long long l,long long r)
{
	if(l>r)
		return one;
	l=l%n,r=r%n;
	matrix s=one;
	for(int d=D-1;d>=0;--d)
		if((1<<d)<=r-l+1)
		{
			s=f[d][l]*s;
			l=l+(1<<d);
		}
	return s;
}
void work()
{/*
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			cout<<"i="<<i<<" j="<<j<<endl;
			print(get_sum(i,j));
		}*/
	for(int i=m;i>=0;--i)
	{
		if(spe_matr[i].first>=k)
			spe_matr[i+1]=spe_matr[i];
		else
		{
			spe_matr[i+1].first=k;
			break;
		}
	}
	++m;
	//print(ans);
	for(int i=1;i<=m;++i)
	{
		//cout<<"i="<<i<<" d="<<spe_matr[i].first<<endl;
		long long d1=spe_matr[i-1].first,d2=spe_matr[i].first;
		ans=spe_matr[i-1].second*ans;
		//print(ans);
		if(d1/n==d2/n)
			ans=get_sum(d1+1,d2-1)*ans;
		else
		{
			ans=get_sum(d1+1,d1/n*n+n-1)*ans;
			//cout<<"multi_seg l="<<d1+1<<" r="<<d1/n*n+n-1<<endl;
			//print(ans);
			
			ans=power(sum,d2/n-d1/n-1)*ans;
			//cout<<"pow t="<<d2/n-d1/n-1<<endl;
			//print(ans);
			ans=get_sum(d2-d2%n,d2-1)*ans;
			//cout<<"multi_seg l="<<d2-d2%n<<" r="<<d2-1<<endl;
			//print(ans);
			/*ans=get_sum(d1+1,d1/n*n+n-1)*ans;
			ans=power(sum,d2/n-d1/n-1)*ans;
			ans=get_sum(d2-d2%n,d2-1)*ans;*/
		}
		//print(ans);
		//cout<<endl;
		if(spe_matr[i].first==k)
			break;
	}
	cout<<ans.a[0][0]<<endl;
}
#undef int 
int main()
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	init();
	if(k==0)
		puts("0");
	else
	{
		get_seg();
		work();
	}
	return 0;
}