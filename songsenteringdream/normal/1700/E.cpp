#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1},o=5e5;
int n,m,s,X[o],Y[o],z,ans;vector<vector<int> > a,b;vector<pair<int,int> > v1,v2,vec;
vector<pair<pair<int,int>,pair<int,int> > > Vec;
inline bool chk(int x,int y){return x>=0&&y>=0&&x<n&&y<m;}
inline int calc(int x,int y){
	if(a[x][y]<2) return 0;
	for(int i=0,tx,ty;i<4;++i) if(chk(tx=x+dx[i],ty=y+dy[i])&&a[tx][ty]<a[x][y]) return 0;
	return 1;
}
template<class T>inline void uni(vector<T>&v){sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());}
int main(){
	scanf("%d%d",&n,&m);a.resize(n);
	for(int i=0,j;i<n;++i) for(a[i].resize(m),j=0;j<m;++j) scanf("%d",&a[i][j]),X[a[i][j]]=i,Y[a[i][j]]=j;
	b=a;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) s+=(b[i][j]=calc(i,j));
	if(!s){putchar(48);return 0;}
	for(z=2;!b[X[z]][Y[z]];++z);
	v1.push_back(make_pair(X[z],Y[z]));
	for(int i=0,tx,ty;i<4;++i) if(chk(tx=X[z]+dx[i],ty=Y[z]+dy[i])) v1.push_back(make_pair(tx,ty));
	for(int i=1;i<z;v2.push_back(make_pair(X[i],Y[i])),++i)
		for(int j=0,tx,ty;j<4;++j) if(chk(tx=X[i]+dx[j],ty=Y[i]+dy[j])) v2.push_back(make_pair(tx,ty));
	uni(v2);
	for(int i=v1.size();i--;) for(int j=v2.size();j--;)
		if(v1[i]!=v2[j]) Vec.push_back(make_pair(min(v1[i],v2[j]),max(v1[i],v2[j])));
	uni(Vec);
	for(int i=Vec.size(),X1,Y1,X2,Y2,s_;i--;){
		X1=Vec[i].first.first;Y1=Vec[i].first.second;X2=Vec[i].second.first;Y2=Vec[i].second.second;s_=s;vec.clear();
		vec.push_back(make_pair(X1,Y1));vec.push_back(make_pair(X2,Y2));
		for(int j=0,tx,ty;j<4;++j) if(chk(tx=X1+dx[j],ty=Y1+dy[j])) vec.push_back(make_pair(tx,ty));
		for(int j=0,tx,ty;j<4;++j) if(chk(tx=X2+dx[j],ty=Y2+dy[j])) vec.push_back(make_pair(tx,ty));
		uni(vec);
		swap(a[X1][Y1],a[X2][Y2]);
		for(int j=vec.size();j--;) s_-=b[vec[j].first][vec[j].second],s_+=calc(vec[j].first,vec[j].second);
		ans+=!s_;swap(a[X1][Y1],a[X2][Y2]);
	}
	if(ans) printf("1 %d",ans);
	else putchar(50);
	return 0;
}