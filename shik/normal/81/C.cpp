// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#define N 100010
using namespace std;
int sc[N],num[N];
vector<int> s1,s2;
void output( vector<int> v ) {
	int n=v.size(),i;
	for ( i=0; i<n; i++ ) printf("%d%c",v[i],i==n-1?'\n':' ');
}
int main()
{
	int n,a,b,i,gap,ca,cnt=0,flg=0;
	scanf("%d%d%d",&n,&a,&b);
	if ( a==b ) {
		for ( i=0; i<a; i++ ) printf("1 ");
		for ( i=0; i<b; i++ ) printf("%d%c",2,i==b-1?'\n':' ');
		return 0;	
	}
	if ( a>b ) swap(a,b),flg=1;
	for ( i=0; i<n; i++ ) scanf("%d",sc+i);
	for ( i=0; i<n; i++ ) num[i]=sc[i];
	sort(num,num+n,greater<int>());
	gap=num[a-1];
	for ( i=0; i<n; i++ )
		if ( sc[i]>gap ) cnt++;
	ca=cnt;
	for ( i=0; i<n; i++ )
		if ( sc[i]>gap ) s1.push_back(1);
		else if ( sc[i]==gap && ca<a ) {
			ca++;
			s1.push_back(1);
		} else s1.push_back(2);
	ca=cnt;
	for ( i=n-1; i>=0; i-- )
		if ( sc[i]>gap ) s2.push_back(2);
		else if ( sc[i]==gap && ca<a ) {
			ca++;
			s2.push_back(2);
		} else s2.push_back(1);
	reverse(s2.begin(),s2.end());
	if ( flg==0 ) output(s1);
	else output(s2);
	//if ( s1<s2 ) output(s1);
	//else output(s2);
	return 0;
}