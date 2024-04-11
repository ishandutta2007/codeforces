#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb[200500],a[200500],res[200500],it;

vector<int> v[200500];
set<int> s;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		k=0;
		memset(a,0,n*4+50);
		memset(res,0,n*4+50);
		s.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			a[j]++;
			sb[i]=j;
			v[i].clear();
		}
		for(i=1;i<=n;i++){
			a[i]=min(a[i],m);
			k+=min(a[i],m);
		}
		k/=m;k*=m;
		it=1;
		
		for(i=1;i<=n;i++){
			if(!a[sb[i]]){continue;}
			a[sb[i]]--;
			v[sb[i]].push_back(i);
			s.insert(sb[i]);
			k--;
			if(!k){break;}
			
		}
		for(auto i:s){
			for(auto j:v[i]){
				res[j]=it;
				it++;
				if(it>m){it=1;}
			}
		}
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}
		puts("");
	}
}