#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct T{string s;int a[100];int P;};
const int p[10]={25,18,15,12,10,8,6,4,2,1};
map<string,T>a;
int n;
#define chkP() if(a.P!=b.P)return a.P>b.P
#define chka() for(int i=0;i<100;i++)if(a.a[i]!=b.a[i])return a.a[i]>b.a[i]
#define chka0() if(a.a[0]!=b.a[0])return a.a[0]>b.a[0]
inline bool cmp(const T&a,const T&b){chkP();chka();return 1;}
inline bool cmq(const T&a,const T&b){chka0();return cmp(a,b);}
int main()
{
	scanf("%d\n",&n);
	for(int i=0,m;i<n;i++)
	{
		scanf("%d\n",&m);
		for(int j=0;j<m;j++)
		{
			string s;
			getline(cin,s);
			a[s].s=s,a[s].a[j]++;
			if(j<10)a[s].P+=p[j];
		}
	}
	vector<T> A;
	for(map<string,T>::iterator I=a.begin();I!=a.end();I++)
		A.push_back(I->second);
	sort(A.begin(),A.end(),cmp);
	cout<<A.front().s<<endl;
	sort(A.begin(),A.end(),cmq);
	cout<<A.front().s<<endl;
	return 0;
}