#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=4e5+5,P=1e9+7;
typedef long double ld;
typedef long long ll;
map<int,int>mp;
set<int>st,ha,ed;
int n,x,opt[N],cnt0,cnt1;
char s[10];
bool check(){
	//for(auto pr:mp)if(pr.second==0)pr.second=1;
	st.clear();ha.clear();ed.clear();
	rep(i,n){
		int x=opt[i];
		if(x>0){
			if(st.size()&&x<*st.rbegin())mp[x]=-1,st.insert(x);
			else if(ed.size()&&*ed.begin()<x)mp[x]=1,ed.insert(x);
			else ha.insert(x);
		}else{
			x=-x;
			if(mp[x]==-1){
				if(!st.size()||*st.rbegin()!=x)return 0;
				st.erase(x);
				for(auto num:ha)mp[num]=1,ed.insert(num);
				ha.clear();
			}else if(mp[x]==1){
				if(!ed.size()||*ed.begin()!=x)return 0;
				ed.erase(x);
				for(auto num:ha)mp[num]=-1,st.insert(num);
				ha.clear();
			}else{
				++cnt1;ha.erase(x);
				for(auto num:ha)
					if(num<x)mp[num]=-1,st.insert(num);
					else mp[num]=1,ed.insert(num);
				ha.clear();
			}
		}
		/*if(x>0){
			if(mp[x]==-1){
				if(hd&&hd<x){
					mp[hd]=-1;
					if(ed.size()&&*ed.begin()<hd)return 0;
					st.insert(hd);
					hd=0;
				}
				if(ed.size()&&*ed.begin()<x)return 0;
				st.insert(x);
			}else if(mp[x]==1){
				if(hd&&x<hd){
					mp[hd]=1;
					if(st.size()&&hd<*st.rbegin())return 0;
					ed.insert(hd);
					hd=0;
				}
				if(st.size()&&x<*st.rbegin())return 0;
				ed.insert(x);
			}else{
				hd=x;
			}
		}else{
			x=-x;
			if(mp[x]==-1){
				if(!st.size()||*st.rbegin()!=x)return 0;
				st.erase(x);
			}else if(mp[x]==1){
				if(!ed.size()||*ed.begin()!=x)return 0;
				ed.erase(x);
			}else{
				hd=0;
			}
		}*/
	}
	cnt0=ha.size()+1;
	return 1;
}
int pw(int x,int y){
	int s=1;
	for(;y;y>>=1,x=1ll*x*x%P)
		if(y&1)s=1ll*s*x%P;
	return s;
}
/*void sol1(){
	st.clear();
	rep(i,n){
		int x=opt[i];
		if(x>0){
			for(auto num:st)
				if(num<x)mp[num]=-1;else mp[num]=1;
			st.clear();st.insert(x);
		}else{
			x=-x;
			if(st.find(x)!=st.end())st.erase(x);
		}
	}
}
void sol2(){
	st.clear();
	rep(i,n){
		int x=opt[i];
		if(x>0){
			st.insert(x);
		}else{
			x=-x;
			for(auto num:st){
				if(num<x)mp[num]=-1;
				else if(num>x)mp[num]=1;
			}
			st.clear();
		}
	}
}*/
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s%d",s,&x);
		if(s[1]=='D')opt[i]=x;else opt[i]=-x;
		mp[x]=0;
	}
	//sol1();
	//sol2();
	cnt0=cnt1=0;
	if(!check()){puts("0");return 0;}
	/*int cnt=0;
	for(auto pr:mp){
		//printf("%d %d\n",pr.first,pr.second);
		if(pr.second==0)++cnt;
	}*/
	printf("%lld\n",1ll*cnt0*pw(2,cnt1)%P);
	return 0;
}