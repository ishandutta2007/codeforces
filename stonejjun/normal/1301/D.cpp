#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll arr[1010101];
ll brr[1010101];
ll dp[1010101];

struct poi{
	char c;
	ll siz;
};

string s1,s2,s3;
queue<poi> s;



int main(){
	ll i,j,k,l,m,n,b,c,d,mini=1e10,maxi=-1e10,chamax=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	ll all=4*n*m-2*n-2*m;
	if(k>all){
		printf("NO");
		return 0;
	}
	poi a;
	printf("YES\n");
	ll now=0;
	for(i=1;i<=m-1;i++){
		if(k<=now+n-1){
			ll left=k-now;
			a.c='D';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;
			break;
		}
		a.c='D';
		a.siz=n-1;
		if(a.siz!=0) s.push(a);
		now+=(n-1);
		if(k<=now+n-1){
			ll left=k-now;
			a.c='U';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;
			break;
		}
		a.c='U';
		a.siz=n-1;
		if(a.siz!=0) s.push(a);
		now+=(n-1);
		if(k<=now+1){
			ll left=k-now;
			a.c='R';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;
			break;
		}
		a.c='R';
		a.siz=1;
		if(a.siz!=0) s.push(a);
		now+=1;
	}

	if(k>now){
		for(i=1;i<=n-1;i++){
		if(k<=now+1){
			ll left=k-now;
			a.c='D';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;

			break;
		}
		a.c='D';
		a.siz=1;
		if(a.siz!=0) s.push(a);
		now+=1;
		if(k<=now+m-1){
			ll left=k-now;
			a.c='L';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;

			break;
		}
		a.c='L';
		a.siz=m-1;
		if(a.siz!=0) s.push(a);
		now+=(m-1);
		if(k<=now+m-1){
			ll left=k-now;
			a.c='R';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;

			break;
		}
		a.c='R';
		a.siz=m-1;
		if(a.siz!=0) s.push(a);
		now+=(m-1);
	}
	} 

	if(k>now){
		if(k<=now+n-1){
			ll left=k-now;
			a.c='U';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;
		}
		else{
			a.c='U';
			a.siz=n-1;
			if(a.siz!=0) s.push(a);
			now+=n-1;
		}
	}
	if(k>now){
		if(k<=now+m-1){
			ll left=k-now;
			a.c='L';
			a.siz=left;
			if(a.siz!=0) s.push(a);
			now=k;
		}
		else{
			a.c='L';
			a.siz=m-1;
			if(a.siz!=0) s.push(a);
			now+=m-1;
		}
	}

	printf("%lld\n",(ll)s.size());
	while(!s.empty()){
		a=s.front();
		s.pop();
		cout<<a.siz<<' '<<a.c<<'\n';
	}
	
}