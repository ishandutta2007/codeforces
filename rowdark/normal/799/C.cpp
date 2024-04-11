#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > C,D;
vector<pair<int,int> > bestC,bestD;
void build(vector<pair<int,int>> &A,vector<pair<int,int>> &B){
	sort(A.begin(),A.end());
	for(int i=0;i<int(A.size());++i){
		if(i==0) B.emplace_back(i,-1);
		else{
			pair<int,int> tmp=B.back();
			if(tmp.second==-1||A[tmp.second].second<A[i].second){
				tmp.second=i;
				if(A[tmp.first].second<A[i].second){
					swap(tmp.first,tmp.second);		
				}
			}
			B.push_back(tmp);
		}
	}
}
int n,c,d;
void Update(int &ans,int lim,vector<pair<int,int>> &A,vector<pair<int,int>> &B){
	for(int i=0,j=int(A.size()-1);i<(int)A.size();++i){
		while(j>i){
			if(A[j].first+A[i].first>lim) --j;
			else break;
		}
		if(j==i) break;
		int k=B[j].first;
		if(k==i) k=B[j].second;
		ans=max(ans,A[i].second+A[k].second);
	}
}
int main(){
	scanf("%d%d%d",&n,&c,&d);
	for(int i=0;i<n;++i){
		int x,y;char s[10];
		scanf("%d%d%s",&x,&y,s);
		if(s[0]=='C'){
			if(y<=c){
				C.emplace_back(y,x);
			}
		}
		else{
			if(y<=d){
				D.emplace_back(y,x);
			}
		}
	}
	build(C,bestC);
	build(D,bestD);
	int ans=0;
	if(C.size()>0&&D.size()>0){
		ans+=C[bestC.back().first].second;
		ans+=D[bestD.back().first].second;
	}
	Update(ans,c,C,bestC);
	Update(ans,d,D,bestD);
	printf("%d\n",ans);
	return 0;
}