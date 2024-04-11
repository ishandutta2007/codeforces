#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
const int oo=0x3f3f3f3f;
int n,q;

const int S=19;
const int N=1<<S;
int a[N];
/*
int t[2*N][S][S];
void add(int x,int y){
	x+=N;
	vector<int>v;
	for(int j=0;j<S;++j){
		if(y>>j&1)
			v.emplace_back(j);
	}
	while(x>=1){
		for(int j=0;j+1<v.size();++j){
			int a=v[j];
			int b=v[j+1];
			while(a!=t[x][a])a=t[x][a];
			while(b!=t[x][b])b=t[x][b];
			if(a!=b)
				t[x][a]=b;
		}
		x>>=1;
	}
}
void que(int l,int r,int x,int y){
	l+=N;
	r+=N;
	static int cur[S];
	iota(cur,cur+S,0);
}
*/
struct que{
	 int l,r,i;
	 bool operator<(que b)const{
		  return r<b.r;
	 }
};
int rofl[S][S];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
//	for(int i=0;i<2*N;++i)
//		iota(t[i],t[i]+S,0);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	vector<que>ques;
	for(int i=0;i<q;++i){
		 int l,r;
		 cin>>l>>r;
		 --l;
		 --r;
		 ques.push_back({l,r,i});
	}
	sort(ques.begin(),ques.end());
	memset(rofl,-0x3f,sizeof rofl);
	vector<bool>ans(q);
	int ptr=0;
	for(int i=0;i<n;++i){
		int x=a[i];
		for(int a=0;a<S;++a)
			for(int b=0;b<=a;++b){
				if(x>>a&1)
					if(x>>b&1){
						rofl[a][b]=rofl[b][a]=i;
						for(int f=0;f<S;++f)
							rofl[f][a]=rofl[f][b]=max(rofl[f][b],rofl[f][a]);
					}
			}
		while(ptr<q&&ques[ptr].r==i){
			bool f=false;
			int le=ques[ptr].l,ri=ques[ptr].r;
			le=a[le],ri=a[ri];
			for(int a=0;a<S;++a)
				for(int b=0;b<S;++b)
					if((le>>a&1)&&(ri>>b&1)&&rofl[a][b]>=ques[ptr].l)
						f=true;
			ans[ques[ptr].i]=f;
			++ptr;
		}
	}
	for(int i=0;i<q;++i)
		if(!ans[i])
			cout<<"Fou\n";
		else
			cout<<"Shi\n";

	return 0;
}