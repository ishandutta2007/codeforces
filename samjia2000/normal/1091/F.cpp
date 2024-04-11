#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 1e5+5;
const LL INF = 1e18;

int n;
LL len[N];
char s[N];
struct func{
	int id;
	LL k,res;
	func(const LL k_=0,const LL res_=0,const int id_=0){k=k_;res=res_;id=id_;}
	friend bool operator <(func a,func b){return a.k!=b.k?a.k<b.k:a.id<b.id;}
};
set<func>st;

int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%I64d",&len[i]);
	scanf("%s",s+1);
	st.clear();
	LL ans=0;
	fo(i,1,n){
		LL res=len[i];
		ans=ans+len[i];
		if (s[i]=='G')st.insert(func(2,len[i]*2,i));
		if (s[i]=='W')st.insert(func(1,len[i]*2,i));
		for(;res;){
			func u=*st.begin();
			st.erase(st.begin());
			int id=u.id;
			if (u.res>res){
				ans=ans+u.k*res;
				u.res-=res;
				res=0;
				st.insert(u);
			}
			else{
				ans=ans+u.k*u.res;
				res-=u.res;
				st.insert(func(s[id]=='G'?5:3,INF,id));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}