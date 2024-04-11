#include <map>
#include <ctime>
#include <cstdio>
#include <algorithm>
typedef long double ld;
typedef long long ll;
const int Maxn=50000;
const ld eps=1e-18;
clock_t begin=clock();
int n,P,Q,m;
ld K[Maxn+5],B[Maxn+5];
struct Segment{
	ld arg;
	int id;
	Segment(ld _arg=0,int _id=0){
		arg=_arg;
		id=_id;
	}
}seg[Maxn<<1|5];
bool cmp_Segment(Segment a,Segment b){
	return a.arg<b.arg;
}
void update_ans(int i,int j,ld &ans){
	ld x=(B[i]-B[j])/(K[j]-K[i]),y=K[i]*x+B[i];
	ans+=sqrtl(x*x+y*y);
	return;
}
void add(int x,int a,std::vector<int> &f){
	for(int i=x;i>0;i-=(i&(-i))){
		f[i]+=a;
	}
}
int query(int x,std::vector<int> &f){
	int ans=0;
	for(int i=x;i<=(int)f.size();i+=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
bool check(ld r){
	int cnt=0;
	for(int i=1;i<=n;i++){
		ld a=K[i]*K[i]+1,b=2*B[i]*K[i],c=-r*r+B[i]*B[i];
		ld d=b*b-4*a*c;
		if(d<eps){
			continue;
		}
		ld x=(-b+sqrtl(d))/a/2,y=K[i]*x+B[i];
		ld tmp_1=atan2(y,x);
		x=(-b-sqrtl(d))/a/2,y=K[i]*x+B[i];
		ld tmp_2=atan2(y,x);
		if(tmp_1>tmp_2){
			std::swap(tmp_1,tmp_2);
		}
		seg[++cnt]=Segment(tmp_1,i);
		seg[++cnt]=Segment(tmp_2,i);
	}
	std::sort(seg+1,seg+1+cnt,cmp_Segment);
	std::vector<int> vis,t;
	vis.resize(n+1),t.resize(cnt+1);
	ll res=0;
	for(int i=1;i<=cnt;i++){
		if(!vis[seg[i].id]){
			vis[seg[i].id]=i;
			add(i,1,t);
		}
		else{
			int j=vis[seg[i].id];
			res+=query(j+1,t);
			add(j,-1,t);
		}
	}
	return res<=m;
}
void get_ans(ld r){
	int cnt=0;
	for(int i=1;i<=n;i++){
		ld a=K[i]*K[i]+1,b=2*B[i]*K[i],c=-r*r+B[i]*B[i];
		ld d=b*b-4*a*c;
		if(d<eps){
			continue;
		}
		ld x=(-b+sqrtl(d))/a/2,y=K[i]*x+B[i];
		ld tmp_1=atan2(y,x);
		x=(-b-sqrtl(d))/a/2,y=K[i]*x+B[i];
		ld tmp_2=atan2(y,x);
		if(tmp_1>tmp_2){
			std::swap(tmp_1,tmp_2);
		}
		seg[++cnt]=Segment(tmp_1,i);
		seg[++cnt]=Segment(tmp_2,i);
	}
	std::sort(seg+1,seg+1+cnt,cmp_Segment);
	ld ans=0;
	std::vector<int> vis;
	vis.resize(n+1);
	std::map<int,int> mp;
	int res=0;
	for(int i=1;i<=cnt;i++){
		if(!vis[seg[i].id]){
			vis[seg[i].id]=i;
			mp[i]=seg[i].id;
		}
		else{
			int j=vis[seg[i].id];
			std::map<int,int>::iterator it=mp.upper_bound(j);
			while(it!=mp.end()){
				res++;
				update_ans(it->second,seg[i].id,ans);
				it++;
			}
			it=mp.find(j);
			mp.erase(it);
		}
	}
	ans+=(m-res)*r;
	if(ans<eps){
		puts("0");
	}
	else{
		printf("%.9lf\n",(double)(std::max(0.0L,ans)));
	}
}
int main(){
	scanf("%d%d%d%d",&n,&P,&Q,&m);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		K[i]=a/1000.0,B[i]=(b-Q)/1000.0+1.0*a*P/1000000.0;
	}
	ld left=0,right=1e13;
	while(right-left>eps){
		ld mid=(left+right)/2;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid;
		}
		clock_t cur=clock();
		if((cur-begin)*1.0/CLOCKS_PER_SEC>6.0){
			break;
		}
	}
	get_ans(left);
	return 0;
}