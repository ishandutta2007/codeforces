#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000000;
int n,m;
int hp[Maxn+5],num[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&hp[i]);
	}
	vector<int> last={0,n};
	int sum=0;
	for(int i=1;i<m;i++){
		sum+=hp[i];
		last.push_back(sum%n);
	}
	sort(last.begin(),last.end());
	vector<int> sizes;
	for(int i=1;i<(int)last.size();i++){
		sizes.push_back(last[i]-last[i-1]);
	}
	printf("%d\n",(sum+hp[m]+n-1) /n);
	for(int i=0;i<(int)sizes.size();i++){
		printf("%d ",sizes[i]);
	}
	puts("");
	int ptr=0;
	for(int i=1;i<=m;i++){
		while(hp[i]>0){
			hp[i]-=sizes[ptr++];
			printf("%d ",i);
			if(ptr==m){
				ptr=0;
				puts("");
			}
		}
	}
	while(ptr&&ptr++!=m){
		printf("%d ",m);
	}
	puts("");
	return 0;
}