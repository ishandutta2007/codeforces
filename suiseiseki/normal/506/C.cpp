#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=100000;
typedef long long ll;
int n,m,k,p;
struct Bamboo{
	int h,a;
}a[Maxn+5];
struct Node{
	ll day;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.day==q.day){
			return p.id<q.id;
		}
		return p.day<q.day;
	}
	friend bool operator >(Node p,Node q){
		if(p.day==q.day){
			return p.id>q.id;
		}
		return p.day>q.day;
	}
	Node(ll _day=0,int _id=0){
		day=_day;
		id=_id;
	}
};
priority_queue<Node,vector<Node>,greater<Node> > q;
int tim[Maxn+5];
bool check(ll x){
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		if(x-1ll*a[i].a*m<a[i].h){
			q.push(Node(x/a[i].a,i));
			tim[i]=0;
		}
	}
	for(int i=1;!q.empty()&&i<=m;i++){
		for(int j=1;!q.empty()&&j<=k;j++){
			Node u=q.top();
			q.pop();
			if(u.day<i){
				return 0;
			}
			tim[u.id]++;
			if(x+1ll*tim[u.id]*p-1ll*a[u.id].a*m<a[u.id].h){
				q.push(Node((x+1ll*tim[u.id]*p)/a[u.id].a,u.id));
			}
		}
	}
	return q.empty();
}
int main(){
	read(n),read(m),read(k),read(p);
	ll left=0,right=0;
	for(int i=1;i<=n;i++){
		read(a[i].h);
		read(a[i].a);
		right=max(right,a[i].h+1ll*m*a[i].a);
	}
	while(left<right){
		ll mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	cout<<left<<endl;
	return 0;
}