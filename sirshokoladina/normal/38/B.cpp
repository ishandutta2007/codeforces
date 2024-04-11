#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

bool bljat(int a1, int a2, int b1, int b2){
	int x=abs(a1-b1);
	int y=abs(a2-b2);
	if(x>y)
		swap(x,y);
	return ( (x==1 && y==2) || (x==0 && y==0) );
}

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	string s1,s2;
	cin>>s1>>s2;
	int a1=s1[0]-'a';
	int a2=s1[1]-'1';
	int b1=s2[0]-'a';
	int b2=s2[1]-'1';
	int ans=0;
	forn(c1,8)
		forn(c2,8){
			bool good=1;
			if(b1==a1 || b2==a2 || c1==a1 || c2==a2)
				good=0;
			if(bljat(a1,a2,b1,b2) || bljat(a1,a2,c1,c2) || bljat(b1,b2,c1,c2))
				good=0;
			ans+=good;
		}
	cout<<ans;
	return 0;
}