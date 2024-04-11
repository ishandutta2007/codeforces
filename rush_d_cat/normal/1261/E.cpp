#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int n, a[N];
int ans[N][N];

int main() {
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//a[i]=rand()%n+1;
	}
	
	vector< vector<int> > P;
	vector<int> cur; for(int i=1;i<=n+1;i++) cur.push_back(i); P.push_back(cur);
	
	for(int i=1;i<=n;i++){
		//printf("i=%d,a=%d\n", i,a[i]);
		int s=0;
		for(auto vec: P) s+=vec.size();
		//printf("s=%d\n", s);
		if(a[i]*2<=n+1) {
			vector< vector<int> > nP; nP.clear();
			int res=a[i];
			for(auto vec: P) {
				if(vec.size()==1) continue;
				int cnt;
				if(vec.size()>=2){
					cnt=min((int)vec.size()-1, res);
				}else{
					cnt=min(1,res);
				}
				vector<int> v1, v2;
				for(int j=0;j<cnt;j++) {
					v1.push_back(vec[j]); ans[i][vec[j]]=1;
				}
				for(int j=cnt;j<vec.size();j++) {
					v2.push_back(vec[j]);
				}

				if(v1.size()) nP.push_back(v1); 
				if(v2.size()) nP.push_back(v2);
				res-=cnt;	
			}

			for(auto vec: P) {
				if(vec.size()>=2) continue;
				int cnt;
				if(vec.size()>=2){
					cnt=min((int)vec.size()-1, res);
				}else{
					cnt=min(1,res);
				}
				vector<int> v1, v2;
				for(int j=0;j<cnt;j++) {
					v1.push_back(vec[j]); ans[i][vec[j]]=1;
				}
				for(int j=cnt;j<vec.size();j++) {
					v2.push_back(vec[j]);
				}
				if(v1.size()) nP.push_back(v1); 
				if(v2.size()) nP.push_back(v2);
				res-=cnt;	
			}
			P=nP;
		}else{
			vector< vector<int> > nP; nP.clear();
			int res=n+1-a[i];
			for(int j=1;j<=n+1;j++) ans[i][j]=1;

			for(auto vec: P) {
				if(vec.size()==1) continue;
				int cnt;
				if(vec.size()>=2){
					cnt=min((int)vec.size()-1, res);
				}else{
					cnt=min(1,res);
				}
				vector<int> v1, v2;
				for(int j=0;j<cnt;j++) {
					v1.push_back(vec[j]); ans[i][vec[j]]=0;
				}
				for(int j=cnt;j<vec.size();j++) {
					v2.push_back(vec[j]);
				}
				if(v1.size()) nP.push_back(v1); 
				if(v2.size()) nP.push_back(v2);
				res-=cnt;	
			}
			for(auto vec: P) {
				if(vec.size()>=2) continue;
				int cnt;
				if(vec.size()>=2){
					cnt=min((int)vec.size()-1, res);
				}else{
					cnt=min(1,res);
				}
				vector<int> v1, v2;
				for(int j=0;j<cnt;j++) {
					v1.push_back(vec[j]); ans[i][vec[j]]=0;
				}
				for(int j=cnt;j<vec.size();j++) {
					v2.push_back(vec[j]);
				}
				if(v1.size()) nP.push_back(v1); 
				if(v2.size()) nP.push_back(v2);
				res-=cnt;	
			}		
			P=nP;	
		}
	}

	printf("%d\n", n+1);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			printf("%d", ans[j][i]);
		}
		printf("\n");
	}
}