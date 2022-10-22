#include<iostream>
#include<queue>
using namespace std;
const int o=40010;
int T,pri[o],cnt,tp,ans;bool vis[o];long long v;
struct yny{
	int pw,b;long long val;
	inline bool operator<(const yny&whx)const{
		if(pw^whx.pw) return pw<whx.pw;
		return b>whx.b;
	}
}st[o];
priority_queue<yny> q;
int main(){
	for(int i=2;i<o;++i) if(!vis[i]) for(int j=pri[++cnt]=i;j<o;j+=i) vis[j]=1;
	for(cin>>T;T--;cout<<"! "<<ans*2<<endl){
		priority_queue<yny>().swap(q);ans=1;
		for(int i=1;i<=cnt;++i) q.push((yny){1,pri[i],pri[i]});
		for(int i=22;i--;tp=0){
			for(v=1;!q.empty();v*=st[tp].val){
				st[++tp]=q.top();q.pop();
				if(v*1.0*st[tp].val>1e18){--tp;break;}
			}
			cout<<"? "<<v<<endl;cin>>v;
			for(int i=1;i<=tp;++i) if(v%st[i].val==0) ans/=st[i].pw,ans*=++st[i].pw,st[i].val*=st[i].b,q.push(st[i]);
		}
	}
	return 0;
}