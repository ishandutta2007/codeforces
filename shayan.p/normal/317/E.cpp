// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define y1 ye_chizi_ke_tooye_matn_nayad

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=210,Base=102,far=7000;

bool is[maxn][maxn];
int pr[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int x1,x2,y1,y2;
pii UU={0,0},RR={0,0},DD={maxn,maxn},LL={maxn,maxn};

vector<int>ans,path;

void go(int k,int NUM=-1){
    if((x1+dx[k])<0 || (x1+dx[k])>=maxn || (y1+dy[k])<0 || (y1+dy[k])>=maxn || !is[x1+dx[k]][y1+dy[k]])
	x1+=dx[k],y1+=dy[k];
    ans.PB(k);
    if((x2+dx[k])<0 || (x2+dx[k])>=maxn || (y2+dy[k])<0 || (y2+dy[k])>=maxn || !is[x2+dx[k]][y2+dy[k]])
	x2+=dx[k],y2+=dy[k];
}

void add_path(int xx,int yy,bool yes=0){
    vector<int>vv;
    while(pr[xx][yy]!=-1){
	int x=pr[xx][yy]-1;
	vv.PB(x);
	xx-=dx[x];
	yy-=dy[x];
    }
    reverse(vv.begin(),vv.end());
    for(int x:vv){
	if(yes)
	    go(x,111);
	else
	    ans.PB(x);
    }
}

void solve1(){
    add_path(0,0,1);
    for(int i=0;i<far;i++)
	go(3,-5);
    if(x2>=0 && y2>=0 && y2<maxn && x2<maxn){
	memset(pr,0,sizeof pr);
	pr[x2][y2]=-1;
	queue<pii> q;
	q.push({x2,y2});
	while(!q.empty()){
	    pii p=q.front();
	    q.pop();
	    for(int i=0;i<4;i++){
		int x=p.F+dx[i],y=p.S+dy[i];
		if(x>=0 && y>=0 && x<maxn && y<maxn && !is[x][y] && pr[x][y]==0){
		    pr[x][y]=i+1;
		    q.push({x,y});
		}
	    }
	}
	add_path(0,0,1);
    }

    if(y2>y1){// down
	while(x2<DD.F)
	    go(0,0);
	while(x2>DD.F)
	    go(2,1);
	while(y2>y1)
	    go(1,2);
    }
    while(x1>=LL.F || x2>=LL.F)
	go(2,3);	

    if(x2>x1){// left
	while(y2<LL.S)
	    go(1,4);
	while(y2>LL.S)
	    go(3,5);
	while(x2>x1)
	    go(0,6);
    }
    while(y1<=UU.S || y2<=UU.S)
	go(1,7);
    
    if(y1>y2){// up
	while(x2<UU.F)
	    go(0,8);
	while(x2>UU.F)
	    go(2,9);
	while(y1>y2)
	    go(3,10);
    }
    while(x1<=RR.F || x2<=RR.F)
	go(0,11);
    
    if(x1>x2){// right
	while(y2<RR.S)
	    go(1,12);
	while(y2>RR.S)
	    go(3,13);
	while(x1>x2)
	    go(2,14);
    }
}

void solve2(){
    add_path(x2,y2);
    path=ans;
    ans.clear();
    int pt=0;
    while(x1!=x2 || y1!=y2){
	int bx=x2,by=y2;
	go(path[pt],118);
	if(bx!=x2 || by!=y2)
	    path.PB(path[pt]);
	pt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>x1>>y1>>x2>>y2;
    x1+=Base;x2+=Base;y1+=Base;y2+=Base;
    int m;cin>>m;

    if(m==0)
	return cout<<-1<<endl,0;
    
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	a+=Base;b+=Base;
	if(RR.F<a) RR={a,b};
	if(a<LL.F) LL={a,b};
	if(UU.S<b) UU={a,b};
	if(b<DD.S) DD={a,b};
	is[a][b]=1;
    }

    pr[x1][y1]=-1;
    queue<pii> q;
    q.push({x1,y1});
    while(!q.empty()){	
	pii p=q.front();
	q.pop();
	for(int i=0;i<4;i++){
	    int x=p.F+dx[i],y=p.S+dy[i];
	    if(x>=0 && y>=0 && x<maxn && y<maxn && !is[x][y] && pr[x][y]==0){
		pr[x][y]=i+1;
		q.push({x,y});
	    }
	}
    }
    
    if(pr[x2][y2]==0)
	return cout<<-1<<endl,0;

    int svx1=x1,svx2=x2,svy1=y1,svy2=y2;
    
    if(pr[0][0]==0)
	solve2();
    else
	solve1();

    x1=svx1;x2=svx2;y1=svy1;y2=svy2;
    for(int i=0;i<sz(ans);i++){
	go(ans[i]);
	if(x1==x2 && y1==y2){
	    for(int j=0;j<=i;j++){
		if(ans[j]==0)
		    cout<<'R';
		if(ans[j]==1)
		    cout<<'U';
		if(ans[j]==2)
		    cout<<'L';
		if(ans[j]==3)
		    cout<<'D';
	    }
	    return cout<<endl,0;
	}
    }
}