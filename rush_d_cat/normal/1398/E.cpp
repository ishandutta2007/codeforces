#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
typedef long long LL;
vector<int> v;
int id(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

struct Nod {
	LL cnt, sum;
	Nod operator+(const Nod&o)const{
		Nod ans;
		ans.cnt = cnt + o.cnt;
		ans.sum = sum + o.sum;
		return ans;
	}
} nod[N<<2];	

void update(int l,int r,int rt,int pos,LL x){
	if(l==r){
		if(x>0){
			nod[rt].cnt++; nod[rt].sum+=x;
		} else {
			nod[rt].cnt--; nod[rt].sum+=x;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
LL query(int l,int r,int rt,int k){
	//printf("que [%d, %d] %d\n", l, r, k);
	//printf("lef cnt = %d, rig cnt = %d\n", nod[rt<<1].cnt, nod[rt<<1|1].cnt);
	if(l==r){
		return 1LL*v[l-1]*min(1LL*k,nod[rt].cnt);
	}
	int mid=(l+r)>>1;
	if(nod[rt<<1|1].cnt<k){
		return nod[rt<<1|1].sum + query(l,mid,rt<<1,k - nod[rt<<1|1].cnt);
	} else {
		return query(mid+1,r,rt<<1|1,k);
	}
}

int n,tp[N],x[N];
set<int> s1,s2;
LL sum1,sum2;
int main() {
	for(int i=0;i<N<<2;i++)nod[i].sum=nod[i].cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tp[i]>>x[i]; v.push_back(abs(x[i]));
	}
       // return 0;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++){
		if(tp[i]==0){
			sum1+=x[i];
			update(1,v.size(),1,id(abs(x[i])),x[i]); 	
			//printf("add %d %d\n", id(abs(x[i])), x[i]);
			if(x[i]>0) s1.insert(x[i]);
			else s1.erase(-x[i]);
		}else{
			sum2+=x[i];
			update(1,v.size(),1,id(abs(x[i])),x[i]);
			//printf("add %d %d\n", id(abs(x[i])), x[i]);
			if(x[i]>0) s2.insert(x[i]);
			else s2.erase(-x[i]);
		}
		LL res=sum1+sum2;
		int cnt=s2.size();
		if(cnt>=1){
			LL val=*s2.begin(); 
			//printf("!!\n");
			//printf("add %d %d\n", id(val), -val);
			update(1,v.size(),1,id(val),-val);
			LL tmp=query(1,v.size(),1,cnt);
			//printf("que %d\n", cnt);
			//printf("add %d %d\n", id(val), val);
			update(1,v.size(),1,id(val),+val);

			res+=tmp;
		}
		printf("%lld\n", res);
	}

}