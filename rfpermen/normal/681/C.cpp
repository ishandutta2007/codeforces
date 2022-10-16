#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
priority_queue<int> pq;
pair<int,ll> p[10000000];
ll n,m,x,tmp;
string s;
int main(){
	cin>>n;
	m=1;
	while(n--){
		cin>>s;
		if(s!="removeMin"){
			cin>>x;
			if(s=="insert")p[m]=mp(1,x), pq.push(-x), m++;
			else {
				while(!pq.empty()){
					if(-pq.top()>=x)break;
					pq.pop(); p[m].fi=0,m++;
				}
				if(pq.empty())p[m]=mp(1,x),m++, pq.push(-x), p[m]=mp(2,x), m++;
				else if(-pq.top()>x)p[m]=mp(1,x),m++, pq.push(-x), p[m]=mp(2,x), m++;
				else p[m]=mp(2,x), m++;
			}
		}
		else if(pq.empty())p[m]=mp(1,0),m++, p[m].fi=0, m++;
		else p[m].fi=0, m++, pq.pop();
		//cout<<p[m-1].fi<<" "<<p[m-1].se<<endl;
	}
	cout<<m-1<<endl;
	rep(i,m-1){
		if(!p[i].fi)printf("removeMin\n");
		else if(p[i].fi==1)printf("insert %lld\n",p[i].se);
		else printf("getMin %lld\n",p[i].se);
	}
	return 0;
}