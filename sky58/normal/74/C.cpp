#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
/*
bool iss(int x,int y){
	if(x==0 && y==0) return true;
	if(x==0 && y==h-1) return true;
	if(x==w-1 && y==0) return true;
	if(x==w-1 && y==h-1) return true;
	return false;
}
*/
int w,h;bool sumi[4100000];
bool iss(int p){
	if(p==0) return true;
	if(p==w-1) return true;
	if(p==w+h-2) return true;
	if(p==2*w+h-3) return true;
	return false;
}
void dfs(int p,int d){
//	cout<<p<<endl;
	if(sumi[p]) return;sumi[p]=true;int np;
	if(d<1){
		if(p<=w*2-2){np=w*2-2-p;}
		else{np=w*4+h*2-6-p;}
	}
	else{
		np=2*w+2*h-4-p;
	}
	if(iss(np)){sumi[np]=true;return;}
	else dfs(np,(d+1)%2);return;
}
int main()
{
	int i,out=0;
	cin>>w>>h;memset(sumi,false,sizeof(sumi));
	int t[4]={0,w-1,w+h-2,w*2+h-3};
	for(i=0;i<4;i++){
		if(!sumi[t[i]]){out++;dfs(t[i],i%2);}
	}
	for(i=0;i<2*w+2*h-4;i++){
		if(!sumi[i]){out++;dfs(i,0);}
	}
	cout<<out<<endl;
	return 0;
}