// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2010;

string s[maxn];
queue<pii>q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pair<char,char> pc[4]={{'^','v'},{'<','>'},{'v','^'},{'>','<'}};
int n,m;

int check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m || s[x][y]!='.')return -1;
    int cnt=0,is=-1;
    for(int k=0;k<4;k++){
	int X=x+dx[k],Y=y+dy[k];
	if(0<=X && X<n && 0<=Y && Y<m){
	    if(s[X][Y]=='.') cnt++,is=k;
	}
    }
    if(cnt!=1) return -1;
    return is;
}

void near(int x,int y){
    for(int i=0;i<4;i++)
	if(check(x+dx[i],y+dy[i])!=-1)
	    q.push({x+dx[i],y+dy[i]});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    if(check(i,j)!=-1)
		q.push({i,j});
    }
    while(sz(q)){
	pii p=q.front();
	q.pop();
	int id=check(p.F,p.S);
	if(id==-1) continue;
	s[p.F][p.S]=pc[id].F;
	s[p.F+dx[id]][p.S+dy[id]]=pc[id].S;
	near(p.F,p.S);
	near(p.F+dx[id],p.S+dy[id]);
    }
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    if(s[i][j]=='.')
		return cout<<"Not unique\n",0;
    for(int i=0;i<n;i++)
	cout<<s[i]<<endl;
    return 0;
}