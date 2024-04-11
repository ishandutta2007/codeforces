#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int key[110000],ka[110000];
lint sum[110000];
vector <vector <int> > tr;
vector <pint> cl;//vector <int> tm;
map<int,int> pre,nex;
void rec(lint sum_,int ka_,int it){
	ka[it]=ka_;sum[it]=sum_;
	if(tr[it].size()<1) return;
	int x=tr[it][0],y=tr[it][1];
	if(key[x]>key[y]){
		rec(sum_+pre[key[it]],ka_+1,x);
		rec(sum_+nex[key[it]],ka_+1,y);
	}
	else{
		rec(sum_+pre[key[it]],ka_+1,y);
		rec(sum_+nex[key[it]],ka_+1,x);
	}
	return;
}
int main()
{
	int i,n,m,a,to;cin>>n;vector <int> tm;
	for(i=0;i<n+10;i++) tr.pb(tm);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&key[i+1]);
		if(a<0) to=i+1;else tr[a].pb(i+1);
		cl.pb(mp(key[i+1],i+1));
	}
	sort(cl.begin(),cl.end());
	for(i=1;i<n-1;i++){
		pre[cl[i].fi]=cl[i-1].fi;nex[cl[i].fi]=cl[i+1].fi;
	}
	rec(0,0,to);
	cin>>m;//cout<<sum[6]<<' '<<ka[6]<<endl;
//	for(i=0;i<cl.size();i++) cout<<cl[i].fi<<' '<<cl[i].se<<endl;
	for(i=0;i<m;i++){
		scanf("%d",&a);
		int hi=n-1,lo=0,it;
		while(hi>lo){
			int mi=(lo+hi+1)/2;
			if(cl[mi].fi>a) hi=mi-1;else lo=mi;//cout<<hi<<' '<<lo<<endl;
		}
//		cout<<hi<<' '<<cl[hi].fi<<' '<<cl[hi].se<<endl;
		if(hi<1 || hi>n-2) it=cl[hi].se;
		else{
			if(tr[cl[hi].se].size()<1) it=cl[hi].se;
			else it=cl[hi+1].se;
		}
		printf("%.12f\n",1.0*sum[it]/ka[it]);
	}
	return 0;
}