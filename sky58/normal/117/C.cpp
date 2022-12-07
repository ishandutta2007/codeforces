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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
char gr[5100][5100];
int so[5100];
bool sumi[5100];
int now=0,n;
void rec(int a){
	if(sumi[a]) return;sumi[a]=true;
	for(int i=0;i<n;i++){
		if(gr[a][i]=='1') rec(i);
	}
	so[a]=now;now++;return;
}
int main()
{
	int i,j,k;cin>>n;
	for(i=0;i<n;i++){
		scanf("%s",&gr[i]);
	}
	for(i=0;i<n;i++){
//		for(j=0;j<n;j++) cout<<gr[i][j];cout<<endl;
	}
	for(i=0;i<n;i++) rec(i);
	for(i=0;i<n;i++) for(j=0;j<n;j++){
		if(so[i]>so[j] && gr[j][i]=='1'){
			for(k=0;k<n;k++){
				if(gr[i][k]=='1' && gr[k][j]=='1'){
					cout<<j+1<<' '<<i+1<<' '<<k+1<<endl;return 0;
				}
			}
		}
	}
	cout<<"-1"<<endl;return 0;
}