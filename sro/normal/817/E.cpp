#include <bits/stdc++.h>
using namespace std;

map<int,int> mp[35];

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int mode;
		scanf("%d",&mode);
		if(mode==1){
			int x;
			scanf("%d",&x);
			for(int i=0;i<30;i++){
				mp[i][x>>i]++;
			}
		}else if(mode==2){
			int x;
			scanf("%d",&x);
			for(int i=0;i<30;i++){
				mp[i][x>>i]--;
			}
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			int ans=0;
			for(int i=0;i<30;i++){
				if((y>>i)&1){
					ans+=mp[i][((x^y)>>i)^1];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}