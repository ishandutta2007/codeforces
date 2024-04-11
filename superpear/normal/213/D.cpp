#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<double,double> PII;
const double PI=acos(-1);
const double tenc2=10*cos(0.2*PI);
const double tenc4=10*cos(0.4*PI);
const double tens2=10*sin(0.2*PI);
const double tens4=10*sin(0.4*PI);

PII a[1000];
int n,o,e,t;

void print()
{
	cout<<t<<" ";
}

int main()
{
	scanf("%d",&n);
	o=1;
	a[o]=m_p(0,0);
	for (int i=1;i<=n/2;i++)
	{
		++o;a[o]=m_p(a[o-1].first-tenc2,a[o-1].second+tens2);
		++o;a[o]=m_p(a[o-2].first+tenc2,a[o-2].second+tens2);
		++o;a[o]=m_p(a[o-2].first+tenc4,a[o-2].second+tens4);
		++o;a[o]=m_p(a[o-2].first-tenc4,a[o-2].second+tens4);
		++o;a[o]=m_p(a[o-2].first-tenc4,a[o-2].second+tens4);
		++o;a[o]=m_p(a[o-2].first+tenc4,a[o-2].second+tens4);
		++o;a[o]=m_p(0,a[o-1].second+tens2);
	}
	if (n%2==1)
	{
		++o;a[o]=m_p(a[o-1].first-tenc2,a[o-1].second+tens2);
		++o;a[o]=m_p(a[o-2].first+tenc2,a[o-2].second+tens2);
		++o;a[o]=m_p(a[o-2].first+tenc4,a[o-2].second+tens4);
		++o;a[o]=m_p(a[o-2].first-tenc4,a[o-2].second+tens4);
	}
	printf("%d\n",o);
	for (int i=1;i<=o;i++)
		printf("%.10lf %.10lf\n",a[i].first,a[i].second);
	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
		{
			e=i/2*7+1;
			printf("%d %d %d %d %d\n",e,e+1,e+3,e+4,e+2);
		}
		else
		{
			e=(i/2-1)*7+4;
			printf("%d %d %d %d %d\n",e,e+2,e+4,e+3,e+1);
		}
	}
	t=1;
	print();
	for (int i=1;i<=n/2;i++)
	{
		t+=3;
		print();
		t--;
		print();
		t--;
		print();
		t+=3;
		print();
		t++;
		print();
		t++;
		print();
		t-=3;
		print();
		t+=4;
		print();
	}
	if (n%2==0)
	{
		for (int i=1;i<=n/2;i++)
		{
			t-=3;
			print();
			t-=4;
			print();
		}
	}
	else
	{
		t+=3;
		print();
		t--;
		print();
		t--;
		print();
		t+=3;
		print();
		t-=4;
		print();
		for (int i=1;i<=n/2;i++)
		{
			t-=3;
			print();
			t-=4;
			print();
		}
	}
	cout<<endl;
	
    return 0;
}