#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int x[505],y[505];
int px[505],py[505];

bool SortbyX(int a,int b){
	return x[a]<x[b];
}

bool SortbyY(int a,int b){
	return y[a]<y[b];
}

bool check(int M){
	int mn[2],mx[2];
	for(int ro=0;ro<2;ro++){
		mn[ro]=n+1;
		mx[ro]=0;
		vector<int> can;//
		can.push_back(1);
		can.push_back(n);
		for(int i=1;i<=k;i++){
			can.push_back(x[i]-M-1);
			can.push_back(x[i]+M+1);
		}
		for(int i=0;i<can.size();i++){
			int X=can[i];
			if(X<1||X>n){
				continue;
			}
			vector<pair<int,int> > now;
			for(int i=1;i<=k;i++){
				if(x[i]+M>=X&&x[i]-M<=X){
					now.push_back(make_pair(y[i]-M,y[i]+M));
				}
			}
			bool shit=0;
			if(now.size()==0){
				shit=1;
				goto bigshit;
			}
			sort(now.begin(),now.end());
			if(now[0].first>1){
				shit=1;
			}
			for(int i=1;i<now.size();i++){
				if(now[i].first>now[i-1].second+1){
					shit=1;
					break;
				}
			}
			if(now.back().second<m){
				shit=1;
			}
			bigshit:;
			if(shit){
				mn[ro]=min(mn[ro],X);
				mx[ro]=max(mx[ro],X);
			}
		}
		swap(n,m);
		for(int i=1;i<=k;i++){
			swap(x[i],y[i]);
		}
	}
	if(max(mx[1]-mn[1],mx[0]-mn[0])<=2*M){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",x+i,y+i);
		px[i]=i;
		py[i]=i;
	}
	sort(px+1,px+k+1,SortbyX);
	sort(py+1,py+k+1,SortbyY);
	int l=-1,r=1000000001;
	while(r-l>1){
		int m=(l+r)>>1;
		if(check(m)){
			r=m;
		}else{
			l=m;
		}
	}
	printf("%d\n",r);
	return 0;
}