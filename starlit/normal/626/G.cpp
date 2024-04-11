#include<bits/stdc++.h>
const int N=200005;
using namespace std;
typedef double db;
const db eps=1e-9;
typedef pair<db,int>pi;
int n,t,q,a[N],b[N],p[N],op;
db ans;
pi ta,tb;
struct pq{
	priority_queue<pi>q,d;
	inline pi top(){
		for(;d.size()&&q.top()==d.top();)
		q.pop(),d.pop();
		return q.size()?q.top():make_pair((db)-1e9,0);
	}
	inline void ins(db v,int no,bool t){
		//if(t)cerr<<"del ";else cerr<<"ins ";
		//cerr<<"("<<v<<','<<no<<")\n";
		t?d.push({v,no}):q.push({v,no});
	}
}mx,mn;
inline void cal(int x,bool d){
	if(!x)return;
	//cerr<<"cal "<<x<<','<<d<<endl;
	int s=a[x],t=b[x];
	//cerr<<"?"<<s<<' '<<t<<endl;
	db tp=(db)p[x]*s/(s+t);
	if(t<s)mx.ins(tp/(s+t+1),x,d);
	if(t)mn.ins(-tp/(s+t-1),x,d);
}
int main(){
//	freopen("dat.txt","r",stdin);
//	freopen("me.txt","w",stdout);
	scanf("%d%d%d",&n,&t,&q);
	for(;t--;)mn.ins(0,0,0);
	for(int i=1;i<=n;i++)
	scanf("%d",p+i);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),cal(i,0);
	int tmp=0;
	for(;q--;){
		tmp++;
		scanf("%d%d",&op,&t);
		//cerr<<"======="<<3-op*2<<','<<t<<"=======\n";
		ans-=(db)p[t]*b[t]/(a[t]+b[t]),cal(t,1);
		//cerr<<"[?"<<b[t]<<','<<a[t]<<endl;
		if(op<2)a[t]++;
		else if(b[t]>--a[t])b[t]--,mn.ins(0,0,0);
		ans+=(db)p[t]*b[t]/(a[t]+b[t]),cal(t,0);
		//cerr<<"preans "<<ans<<endl;
		//cerr<<"[!"<<b[t]<<','<<a[t]<<endl;
		//cerr<<mx.q.size()<<','<<mn.d.size()<<endl;
		for(;(ta=mx.top()).first+(tb=mn.top()).first>eps;){
			ans+=ta.first+tb.first;
			//if(tmp>4950)
			//cerr<<"Get "<<ta.first<<"&"<<ta.second<<','<<tb.first<<"&"<<tb.second<<endl;
			cal(ta.second,1),cal(tb.second,1);
			if(!tb.second)mn.ins(0,0,1);
			b[ta.second]++,b[tb.second]--;
			cal(ta.second,0),cal(tb.second,0);
		}
		printf("%.7lf\n",ans);
	}
}