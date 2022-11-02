// by shik
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<string,int> tbl;
string name[50];
int get[50],lse[50],pts[50],a,b,ord[50],ok[50];
char s1[50],s2[50];
bool cp( int a, int b ) {
	if ( pts[a]!=pts[b] ) return pts[a]>pts[b];
	if ( get[a]-lse[a]!=get[b]-lse[b] ) return get[a]-lse[a]>get[b]-lse[b];
	if ( get[a]!=get[b] ) return get[a]>get[b];
	return 0;
}
int main()
{
	int n,m,i;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) cin>>name[i];
	sort(name,name+n);
	for ( i=0; i<n; i++ ) tbl[name[i]]=ord[i]=i;
	m=n*(n-1)/2;
	for ( i=0; i<m; i++ ) {
		scanf(" %[^-]-%s %d:%d",s1,s2,&a,&b);
		get[tbl[s1]]+=a;
		get[tbl[s2]]+=b;
		lse[tbl[s1]]+=b;
		lse[tbl[s2]]+=a;
		if ( a>b ) pts[tbl[s1]]+=3;
		else if ( a<b ) pts[tbl[s2]]+=3;
		else pts[tbl[s2]]+=1,pts[tbl[s1]]+=1;
	}
	sort(ord,ord+n,cp);
	for ( i=0; i<n/2; i++ ) ok[ord[i]]=1;
	for ( i=0; i<n; i++ )
		if ( ok[i] ) cout<<name[i]<<endl;
	return 0;
}