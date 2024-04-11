#include<iostream>

using namespace std;

const long long N = 1e5+7;
const long long logA = 20;

long long n,m;
long long a[N];
long long st[4*N][logA+3];
long long lp[4*N][logA+3];

void init(long long ind,long long l,long long r,long long w)
{
	//cout<<l<<" "<<r<<" - "<<ind<<endl;
	//Bcout<<st[5][0]<<endl;

	if(l==r)
	{
		st[ind][w]=a[l]&(1<<w);

		//cout<<ind<<" = "<<l<<" "<<r<<" "<<st[ind][w]<<" - "<<w<<endl;
		return;
	}

	long long mid=(l+r)/2;

	init(2*ind,l,mid,w);
	init(2*ind+1,mid+1,r,w);

	st[ind][w]=st[2*ind][w]+st[2*ind+1][w];

	//cout<<ind<<" = "<<l<<" "<<r<<" "<<st[ind][w]<<" - "<<w<<endl;

	return;
}

void update(long long ind,long long l,long long r,long long sl,long long sr,long long w)
{
	if(lp[ind][w])
	{
		st[ind][w]=(r-l+1)*(1<<w)-st[ind][w];
		if(l!=r)
		{
			lp[2*ind][w]^=lp[ind][w];
			lp[2*ind+1][w]^=lp[ind][w];
		}
		lp[ind][w]=0;
	}
	if(l>sr || r<sl)
		return;
	if(sl<=l && r<=sr)
	{
		st[ind][w]=(r-l+1)*(1<<w)-st[ind][w];
		if(l!=r)
		{
			lp[2*ind][w]^=1;
			lp[2*ind+1][w]^=1;
		}
		return;
	}

	long long mid=(l+r)/2;

	update(2*ind,l,mid,sl,sr,w);
	update(2*ind+1,mid+1,r,sl,sr,w);

	st[ind][w]=st[2*ind][w]+st[2*ind+1][w];

	return;
}

long long query(long long ind,long long l,long long r,long long sl,long long sr,long long w)
{
	//cout<<l<<" to "<<r<<" = "<<st[ind][w]<<" -- "<<lp[ind][w]<<endl;
	if(lp[ind][w])
	{
		st[ind][w]=(r-l+1)*(1<<w)-st[ind][w];
		if(l!=r)
		{
			lp[2*ind][w]^=lp[ind][w];
			lp[2*ind+1][w]^=lp[ind][w];
		}
		lp[ind][w]=0;
	}
	if(l>sr || r<sl)
		return 0;
	if(sl<=l && r<=sr)
		return st[ind][w];

	long long mid=(l+r)/2;

	return query(2*ind,l,mid,sl,sr,w) + query(2*ind+1,mid+1,r,sl,sr,w);
}

int main ()
{
	long long i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(i=1;i<=n;i++)
		cin>>a[i];

	for(i=0;i<=logA;i++)
		init(1,1,n,i);

	//cout<<st[5][0]<<" "<<st[5][1]<<" "<<st[5][2]<<" "<<st[5][3]<<endl;
	//cout<<(1<<0)<<endl;

	cin>>m;

	long long t,l,r,x,res=0,j;

	for(i=0;i<m;i++)
	{
		cin>>t;

		if(t==1)
		{
			cin>>l>>r;

			res=0;

			for(j=0;j<=logA;j++)
				res+=query(1,1,n,l,r,j);

			cout<<res<<"\n";
		}
		else
		{
			cin>>l>>r>>x;

			for(j=0;j<=logA;j++)
				if(x&(1<<j))
					update(1,1,n,l,r,j);
		}
	}

	return 0;
}