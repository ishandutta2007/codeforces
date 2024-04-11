#include<string>
#include<map>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
string S;
char ss[11];
map<string,pair<int,int> > M;
int ans[70001];
string output[70001];
void Update(int x,const string &y){
	if(ans[x]>y.length()) ans[x]=y.length(),output[x]=y;
}
int main(){
	scanf("%d",&N);
	for(int nn=0;nn<N;++nn){
		ans[nn]=9;
		scanf("%s",ss);
		output[nn]=ss;
		for(int i=0;i<9;++i){
			S="";
			for(int j=i;j<9;++j){
				S+=ss[j];
				if(M.count(S)){
					if(M[S].second!=nn) M[S]=make_pair(2,nn);
				}
				else M[S]=make_pair(1,nn);
			}
		}
	}
	for(auto &&x:M){
		if(x.second.first==1){
			Update(x.second.second,x.first);
		}
	}
	for(int nn=0;nn<N;++nn) printf("%s\n",output[nn].c_str());
}