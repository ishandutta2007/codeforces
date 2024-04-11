#include<stdio.h>
#include<ctype.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> rpos,tpos;
vector<string> r,t;
vector<string> nr,nt;
bool valid[100010];
bool geted[100010];
char s[10];
int N;
int getV(const string &s){
	if(s[0]=='0'||!isdigit(s[0])) return -1;
	int ret=0;
	for(int i=0;i<int(s.size());++i){
		if(!isdigit(s[i])) return -1;
		ret=ret*10+s[i]-'0';
	}
	return ret>N?-1:ret;
}
inline bool cmp(const string &s,const string &t){
	return getV(s)<getV(t);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		int x;
		scanf("%s%d",s,&x);
		if(x==0) r.push_back(s);
		else t.push_back(s);
	}
	int e=t.size();
	for(int i=0;i<int(t.size());++i){
		int f=getV(t[i]);
		if(f!=-1){
			geted[f]=1;
			if(f<=e){
				valid[f]=1;
			}
			else nt.push_back(t[i]);
		}
		else nt.push_back(t[i]);
	}
	for(int i=0;i<int(r.size());++i){
		int f=getV(r[i]);
		if(f!=-1){
			geted[f]=1;
			if(f>e){
				valid[f]=1;
			}
			else nr.push_back(r[i]);
		}
		else nr.push_back(r[i]);
	}
	int ans=0;
	for(int i=1;i<=N;++i) if(!valid[i]) ++ans;
	if(ans==0){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=e;++i) if(!geted[i]) tpos.push_back(i);
	for(int i=e+1;i<=N;++i) if(!geted[i]) rpos.push_back(i);
	if(!tpos.size()&&!rpos.size()){
		++ans;
		printf("%d\n",ans);
		printf("move %s 100010\n",nr[0].c_str());
		tpos.push_back(getV(nr[0]));
		nr[0]="100010";
	}
	else printf("%d\n",ans);
	sort(nr.begin(),nr.end(),cmp);
	sort(nt.begin(),nt.end(),cmp);
	while(tpos.size()||rpos.size()){
		while(tpos.size()){
			int v=tpos.back();
			tpos.pop_back();
			int f=getV(nt.back());
			printf("move %s %d\n",nt.back().c_str(),v);
			if(f!=-1) rpos.push_back(f);
			nt.pop_back();
		}
		while(rpos.size()){
			int v=rpos.back();
			rpos.pop_back();
			int f=getV(nr.back());
			printf("move %s %d\n",nr.back().c_str(),v);
			if(f!=-1) tpos.push_back(f);
			nr.pop_back();
		}
	}
	return 0;
}