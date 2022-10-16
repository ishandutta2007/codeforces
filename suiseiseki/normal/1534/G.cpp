#include <queue>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=800000;
int n;
struct Node{
	int a,b;
	Node(int _a=0,int _b=0){
		a=_a,b=_b;
	}
	friend bool operator <(Node a,Node b){
		return a.a<b.a;
	}
}a[Maxn+5];
std::priority_queue<ll> q_l;
std::priority_queue<ll,std::vector<ll>,std::greater<ll> > q_r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
		a[i]=Node(a[i].a+a[i].b,a[i].a);
		q_l.push(0),q_r.push(0);
	}
	std::sort(a+1,a+1+n);
	ll ans=0;
	int last=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		int tmp=a[i].a-last;
		last=a[i].a;
		sum+=tmp;
		if(a[i].b<=q_l.top()){
			ans+=q_l.top()-a[i].b;
			q_l.push(a[i].b);
			q_l.push(a[i].b);
			q_r.push(q_l.top()-sum);
			q_l.pop();
		}
		else if(a[i].b>=q_r.top()+sum){
			ans+=a[i].b-(q_r.top()+sum);
			q_r.push(a[i].b-sum);
			q_r.push(a[i].b-sum);
			q_l.push(q_r.top()+sum);
			q_r.pop();
		}
		else{
			q_l.push(a[i].b);
			q_r.push(a[i].b-sum);
		}
	}
	printf("%lld\n",ans);
	return 0;
}