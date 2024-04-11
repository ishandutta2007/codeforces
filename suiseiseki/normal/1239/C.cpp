#include <set>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
int n,p;
struct Person{
	ll t;
	int id;
	bool tag;
	friend bool operator <(Person p,Person q){
		if(p.t==q.t){
			if(p.tag==q.tag){
				return p.id<q.id;
			}
			return p.tag<q.tag;
		}
		return p.t<q.t;
	}
	friend bool operator >(Person p,Person q){
		if(p.t==q.t){
			if(p.tag==q.tag){
				return p.id>q.id;
			}
			return p.tag>q.tag;
		}
		return p.t>q.t;
	}
}a[Maxn+5];
ll ans[Maxn+5];
Person make_person(ll t,int id,bool tag){
	static Person ans;
	ans.t=t;
	ans.id=id;
	ans.tag=tag;
	return ans;
}
priority_queue<Person,vector<Person>,greater<Person> > q;
set<int> inq,want;
ll mx(ll a,ll b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].t);
		a[i].id=i;
		a[i].tag=0;
	}
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	Person x;
	ll t=0;
	set<int>::iterator it;
	while(!q.empty()){
		x=q.top();
		q.pop();
		if(!x.tag){
			if(inq.empty()||(x.id<(*inq.begin()))){
				t=mx(t,x.t);
				inq.insert(x.id);
				t+=p;
				q.push(make_person(t,x.id,1));
			}
			else{
				want.insert(x.id);
			}
			continue;
		}
		ans[x.id]=x.t;
		inq.erase(x.id);
		while(!want.empty()&&(inq.empty()||(*inq.begin())>(*want.begin()))){
			it=want.begin();
			inq.insert(*it);
			t+=p;
			q.push(make_person(t,(*it),1));
			want.erase(it);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}