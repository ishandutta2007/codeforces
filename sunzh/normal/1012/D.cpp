#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
char s[200010],t[200010];
int n,m;
bool fl;
vector<PII>a,b,ans;
void doit(int x,int y){
	// printf("x:%d,y:%d,%d %d\n",x,y,a.size(),b.size());
	vector<PII>tmp1,tmp2;
	int s1=0,s2=0;
	for(int i=1;i<=x;++i){
		tmp1.pb(a.back());s1+=a.back().se;a.pop_back();
	}
	for(int i=1;i<=y;++i) tmp2.pb(b.back()),s2+=b.back().se,b.pop_back();
	if(fl) ans.pb(mp(s2,s1));else ans.pb(mp(s1,s2));
	while(tmp1.size()){
		PII t=tmp1.back();tmp1.pop_back();
		if(b.size()&&b.back().fi==t.fi) b.back().se+=t.se;else b.pb(t);
 	}
	while(tmp2.size()){
		PII t=tmp2.back();tmp2.pop_back();
		if(a.size()&&a.back().fi==t.fi) a.back().se+=t.se;else a.pb(t);
 	}
}
int main(){
	scanf("%s",s+1);scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;++i){
		if(s[i]!=s[i-1]) a.ep(s[i]-'a',1);
		else a.back().se++;
	}
	for(int i=1;i<=m;++i){
		if(t[i]!=t[i-1]) b.ep(t[i]-'a',1);
		else b.back().se++;
	}
	reverse(a.begin(),a.end());reverse(b.begin(),b.end());
	while(a.size()>1||b.size()>1){
		if(a.size()<b.size()){
			swap(a,b);fl^=1;
		}
		// printf("%d %d\n",a.back().fi,b.back().fi);
		if(a.back().fi==b.back().fi){
			if(b.size()==1){
				//sa-len,len
				int len=(a.size()+1>>1);
				if(!(len&1)) --len;
				doit(len,0);
			}
			else{
				//sa-len,sb+len-2
				//sa-(sa+sb-2/2)
				auto gm=[&](int x,int y){
					if(x<0||x>a.size()) return y;if(y<0||y>b.size()) return x;
					int l=a.size()-x,r=b.size()+x-2,rs1=((l<=0||r<=0)?1e9:abs(l-r));
					l=a.size()-y,r=b.size()+y-2;int rs2=((l<=0||r<=0)?1e9:abs(l-r));
					if(rs1<=rs2) return x;else return y;
				};
				int len=(a.size()-b.size()+2>>1);
				if(len&1) len=gm(len-1,len+1);
				doit(len,1);
			}
		}
		else{
			//a-len,b+len-1
			// auto gm=[&](int x,int y){
			// 	if(x<0||x>a.size()) return y;if(y<0||y>b.size()) return x;
			// 	int l=a.size()-x,r=b.size()+x-1,rs1=((l<=0||r<=0)?1e9:abs(l-r));
			// 	l=a.size()-y,r=b.size()+y-1;int rs2=((l<=0||r<=0)?1e9:abs(l-r));
			// 	if(rs1<=rs2) return x;else return y;
			// };
			int len=(a.size()-b.size()+1>>1)+1;
			if(!(len&1)) --len;
			// else len=gm(gm(len,len+2),len-2);
			doit(len,1);
		}
	}
	if(a.back().fi==b.back().fi){
		doit(1,0);
	}
	printf("%d\n",ans.size());
	for(PII i:ans) printf("%d %d\n",i.fi,i.se);
}