/*
LANG: C++
ID: AnilKishore
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SI ({int x;scanf("%d",&x);x;})

const int mxn = 100003;

int n,m;
LL a[mxn];

int main()
{
	int i,j,k;
	LL s=0,cnt = 0, sr = 0, r;
	cin>>n;
	for(i=0;i<n;i++){ cin>>a[i]; s+=a[i]; }

	if(s%3!=0 || n<3){ puts("0"); exit(0); }
	
	r = s/3;
	s=a[0]; sr=0;

	for(i=1;i<n-1;i++)
	{
		if(s==r) sr++;
		s+=a[i];
		if(s==2*r) cnt+=sr;
	}

	cout<<cnt<<endl;
	return 0;
}