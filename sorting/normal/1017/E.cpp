#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

const long long N=100007;

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	if(x.first<y.first)
		return 1;
	if(x.first>y.first)
		return 0;
	return x.second<y.second;
}

long long Area(pair<long long,long long> a,pair<long long,long long> b,pair<long long,long long> c)
{
	return a.first*b.second+b.first*c.second+c.first*a.second-a.first*c.second-c.first*b.second-b.first*a.second;
}



pair<long long,long long> a[N],b[N];
vector<pair<long long,long long> > va;
vector<pair<long long,long long> > vb;

bool cmp2(pair<long long,long long> x,pair<long long,long long> y)
{
	if(Area(a[0],x,y)==0)
		return x<y;

	return (Area(a[0],x,y)>0);
}

bool cmp3(pair<long long,long long> x,pair<long long,long long> y)
{
	if(Area(b[0],x,y)==0)
		return x<y;


	return (Area(b[0],x,y)>0);
}

clock_t t;

long long dist(pair<long long,long long> p1,pair<long long,long long> p2)
{
	return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

int main ()
{
	long long n,m,i;
	pair<long long,long long> p;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	t=clock();

	cin>>n>>m;

	long long con=1000;

	for(i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;

	for(i=0;i<m;i++)
		cin>>b[i].first>>b[i].second;

	sort(a,a+n,cmp);
	sort(b,b+m,cmp);
	sort(a+1,a+n,cmp2);
	sort(b+1,b+m,cmp3);

	va.push_back(a[0]);
	va.push_back(a[1]);

	for(i=2;i<n;i++)
	{
		p=va.back();
		va.pop_back();

		//cout<<Area(va.back(),p,a[i])<<endl;

		if(!va.empty() && Area(va.back(),p,a[i])<=0)
			i--;
		else
		{
			va.push_back(p);
			va.push_back(a[i]);
		}
	}

	vb.push_back(b[0]);
	vb.push_back(b[1]);
	
	//for(i=0;i<4;i++)
	//	cout<<b[i].first<<" b "<<b[i].second<<endl;

	for(i=2;i<m;i++)
	{
		p=vb.back();
		vb.pop_back();

		if(!vb.empty() && Area(vb.back(),p,b[i])<=0)
			i--;
		else
		{
			vb.push_back(p);
			vb.push_back(b[i]);
		}
	}

	//cout<<va.size()<<" "<<vb.size()<<endl;

	if(va.size()!=vb.size())
	{
		cout<<"NO\n";
		return 0;
	}
	
	int x,y,x2,y2,j;

	//for(i=0;i<va.size();i++)
	//	cout<<va[i].first<<" "<<va[i].second<<" --- "<<vb[i].first<<" "<<vb[i].second<<endl;

	for(i=0;i<vb.size();i++)
	{
		for(j=0;j<con;j++)
		{
			x=rand()%va.size();
			y=rand()%va.size();
			x2=(x+i)%vb.size();
			y2=(y+i)%vb.size();

			if(dist(va[x],va[y])!=dist(vb[x2],vb[y2]))
				break;
		}
		//cout<<j<<endl;
		if(j==con)
		{
			cout<<"YES\n";
			return 0;
		}
	}

	cout<<"NO\n";
	return 0;
}