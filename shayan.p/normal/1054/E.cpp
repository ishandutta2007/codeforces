// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> pi4;

const int maxn=310;

int n,m;
vector<pi4> vec;
deque<bool> d[maxn][maxn];
string ch;

void MV(int x1,int y1,int x2,int y2){
    if(x1==x2 && y1==y2)return;
    vec.PB({{x1,y1},{x2,y2}});
    bool b=d[x1][y1].back();
    d[x1][y1].pop_back();
    d[x2][y2].push_front(b);
}

void MVT(int x1,int y1,int x2,int y2){
    if(x1==x2 && y1==y2)return;
    while(sz(d[x1][y1])) MV(x1,y1,x2,y2);
}

vector<pi4> solve(bool REV){
    vec.clear();
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cin>>ch;
	    if(REV) reverse(ch.begin(),ch.end());
	    d[i][j].clear();
	    for(int k=0;k<sz(ch);k++)
		d[i][j].PB(ch[k]=='1');
	}
    }
    for(int j=0;j<m;j++){
	MVT(0,j,0,m-1);
	MVT(n-1,j,n-1,0);
    }
    for(int i=0;i<n;i++){
	MVT(i,0,n-1,0);
	MVT(i,m-1,0,m-1);
    }
    for(int i=1;i<n-1;i++){
	for(int j=1;j<m-1;j++){
	    while(sz(d[i][j])){
		if(d[i][j].back())
		    MV(i,j,n-1,j);
		else
		    MV(i,j,0,j);
	    }
	}
    }
    for(int j=0;j<m;j++){
	if(j!=m-1)
	    MVT(0,j,0,0);
	if(j!=0)
	    MVT(n-1,j,n-1,m-1);
    }
    while(sz(d[0][m-1])){
	if(d[0][m-1].back())
	    MV(0,m-1,n-1,m-1);
	else
	    MV(0,m-1,0,0);
    }
    while(sz(d[n-1][0])){
	if(d[n-1][0].back())
	    MV(n-1,0,n-1,m-1);
	else
	    MV(n-1,0,0,0);
    }
    return vec;
}

int main(){
    scanf("%d%d",&n,&m);
    vector<pi4> v1=solve(0);
    vector<pi4> v2=solve(1);
    printf("%d\n",sz(v1)+sz(v2));
    for(int i=0;i<sz(v1);i++)
	printf("%d %d %d %d\n",v1[i].F.F+1,v1[i].F.S+1,v1[i].S.F+1,v1[i].S.S+1);
    for(int i=sz(v2)-1;i>=0;i--)
	printf("%d %d %d %d\n",v2[i].S.F+1,v2[i].S.S+1,v2[i].F.F+1,v2[i].F.S+1);
    return 0;
}