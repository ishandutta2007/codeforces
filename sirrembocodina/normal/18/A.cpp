#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pt pair<ld,ld>
#define otr pair<pt,pt>
#define x first
#define y second
#define pi 3.1415926535897932

ld dist(pt a,pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

pt mid(pt a,pt b){
	pt m;
	m.x=(a.x+b.x)/2;
	m.y=(a.y+b.y)/2;
	return m;
}

bool pry(pt a,pt b,pt c){
	if(( abs(dist(a,b)-dist(b,c)-dist(a,c))<0.0000001 )||( abs(dist(a,c)-dist(b,c)-dist(a,b))<0.0000001 )
	||( abs(dist(c,b)-dist(b,a)-dist(a,c))<0.0000001 ))
		return false;
	if(abs( 2*dist(a,mid(b,c))-dist(b,c) )<0.0000001)
		return true;
	if(abs( 2*dist(b,mid(a,c))-dist(a,c) )<0.0000001)
		return true;
	if(abs( 2*dist(c,mid(b,a))-dist(b,a) )<0.0000001)
		return true;
	return false;
}

int main(){
	// freopen("input.txt","rt",stdin);
	// freopen("output.txt","wt",stdout);
	pt a,b,c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	bool pr=pry(a,b,c),al=false;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if((i==0)!=(j==0)){
				pt a1;
				a1.x=a.x+i,a1.y=a.y+j;
				if(pry(a1,b,c))
					al=true;
			}
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if((i==0)!=(j==0)){
				pt b1;
				b1.x=b.x+i,b1.y=b.y+j;
				if(pry(a,b1,c))
					al=true;
			}
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if((i==0)!=(j==0)){
				pt c1;
				c1.x=c.x+i,c1.y=c.y+j;
				if(pry(a,b,c1))
					al=true;
			}
	if(pr)
		cout<<"RIGHT";
	else if(al)
		cout<<"ALMOST";
	else if(!(al||pr))
		cout<<"NEITHER";
}