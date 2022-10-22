#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
string s[300010];
int sx[300010],sy[300010],sz[300010];
bool check(int x,int t){
	int lx,ly,rx,ry,lz,rz;
	if(t==0){
		lx=1,ly=0,rx=0x3f3f3f3f,ry=0x3f3f3f3f,lz=-0x3f3f3f3f,rz=0x3f3f3f3f;
	} 
	else lx=0,ly=1,rx=0x3f3f3f3f,ry=0x3f3f3f3f,lz=-0x3f3f3f3f,rz=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		lx=max(lx,sx[i]-x);
		ly=max(ly,sy[i]-x);
		lz=max(lz,sz[i]-x);
		rx=min(rx,sx[i]+x);
		ry=min(ry,sy[i]+x);
		rz=min(rz,sz[i]+x);
	}
	if(lx>rx||ly>ry||lz>rz||rx-ly<lz||lx-ry>rz) return 0;
	return 1;
}
void print(int x,int t){
	int lx,ly,rx,ry,lz,rz;
	if(t==0){
		lx=1,ly=0,rx=0x3f3f3f3f,ry=0x3f3f3f3f,lz=-0x3f3f3f3f,rz=0x3f3f3f3f;
	} 
	else lx=0,ly=1,rx=0x3f3f3f3f,ry=0x3f3f3f3f,lz=-0x3f3f3f3f,rz=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		lx=max(lx,sx[i]-x);
		ly=max(ly,sy[i]-x);
		lz=max(lz,sz[i]-x);
		rx=min(rx,sx[i]+x);
		ry=min(ry,sy[i]+x);
		rz=min(rz,sz[i]+x);
	}
	int ansx=min(rx,ry+rz);
	int ansy=max(ly,ansx-rz);
	for(int i=1;i<=ansx;++i) cout<<'B';
	for(int i=1;i<=ansy;++i) cout<<'N';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i){
		int l=s[i].length();
		for(int j=0;j<l;++j){
			if(s[i][j]=='B') ++sx[i];
			else ++sy[i];
		}
		sz[i]=sx[i]-sy[i];
	}
	int l=0,r=1000000;
	int res,t;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid,0)){
			res=mid,t=0;r=mid-1;
		}
		else if(check(mid,1)){
			res=mid,t=1;r=mid-1;
		}
		else l=mid+1;
	}
	cout<<res<<'\n';
	print(res,t);
	return 0;
}