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

const int maxn=1e5+10,maxm=12,SQ1=1024,SQ2=1001,LG=12,inf=1e9;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
pii f1[maxn][maxm],f2[maxn][maxm],f3[maxn][maxm][LG];
pii arr[SQ1];

inline int what(char ch){
    if(ch=='<') return 3;
    if(ch=='^') return 2;
    if(ch=='>') return 1;
    return -1;
}

void dfs(int a,int b,int h=0){
    if(h>=SQ1) return;
    if(h!=0) f2[a][b]=arr[SQ1-h];
    pii fix={a,b};
    for(int i=0;i<4;i++){
	if(f1[a+dx[i]][b+dy[i]]==fix)
	    dfs(a+dx[i],b+dy[i],h+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
	string s;cin>>s;
	for(int j=1;j<=m;j++)
	    f1[i][j]={i+dx[what(s[j-1])],j+dy[what(s[j-1])]};
    }
    for(int i=0;i<=n+1;i++){
	f1[i][0]=f2[i][0]={i,0};
	f1[i][m+1]=f2[i][m+1]={i,m+1};
	for(int k=0;k<LG;k++)
	    f3[i][0][k]={i,0},f3[i][m+1][k]={i,m+1};
	for(int j=1;j<=m;j++){
	    if(i==0 || i==n+1){
		f1[i][j]=f2[i][j]={i,j};
		for(int k=0;k<LG;k++)
		    f3[i][j][k]={i,j};
	    }
	    else{
		pii tmp={i,j};
		for(int k=0;k<16;k++){
		    tmp=f1[tmp.F][tmp.S];
		    if(k==0) f3[i][j][0]=tmp;
		    if(k==1) f3[i][j][1]=tmp;
		    if(k==3) f3[i][j][2]=tmp;
		    if(k==7) f3[i][j][3]=tmp;
		    if(k==15) f3[i][j][4]=tmp;
		}
		if(tmp.F==i){
		    for(int k=0;k<LG;k++)
			f3[i][j][k]=tmp;
		}
		else{
		    for(int k=5;k<LG;k++)
			f3[i][j][k]=f3[f3[i][j][k-1].F][f3[i][j][k-1].S][k-1];
		}
		f2[i][j]=f3[i][j][10];// 1024
	    }
	}
    }
    while(q--){
	char task;cin>>task;
	int a,b;cin>>a>>b;
	if(task=='A'){
	    pii tmp={a,b};
	    for(int i=0;i<SQ2;i++)
		tmp=f2[tmp.F][tmp.S];
	    if(tmp.F!=0 && tmp.F!=n+1 && tmp.S!=0 && tmp.S!=m+1)
		tmp={-1,-1};
	    cout<<tmp.F<<" "<<tmp.S<<"\n";
	}
	else{
	    char ch;cin>>ch;
	    f1[a][b]={a+dx[what(ch)],b+dy[what(ch)]};
	    pii tmp={a,b};
	    for(int i=0;i<SQ1;i++)
		arr[i]=tmp,tmp=f1[tmp.F][tmp.S];
	    f2[a][b]=tmp;
	    dfs(a,b);
	}
    }
    return 0;
}