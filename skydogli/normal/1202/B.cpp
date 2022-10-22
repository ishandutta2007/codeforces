#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[2000005];
vector<int>ans[15][15][15];
int ln,cnt[15],sum[15][15];
signed main(){
	scanf("%s",s+1);
	ln=strlen(s+1);
	for(int a=0;a<=9;++a)
		for(int b=0;b<=9;++b)
			for(int s=0;s<=9;++s){
				for(int tot=1;tot<19;++tot)
					for(int x=0;x<=min(tot,9ll);++x){
						int y=tot-x;
						if(y>9)continue;
						if((a*x+b*y)%10==s){
							ans[a][b][s].push_back(tot);		
						}
					}
		}
			
	for(int i=0;i<10;++i)
		for(int j=0;j<=i;++j){
			int num=0;
			s[0]='0';
			for(int k=2;k<=ln;++k){
				
				int S=(s[k]-s[k-1]+10)%10;
				if(ans[i][j][S].size()==0){
					sum[i][j]=-1;
					break;
				}	
				cnt[S]++;
				sum[i][j]+=ans[i][j][S][0];
			}
		}
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			int x=i,y=j;
			if(x<y)swap(x,y);
			printf("%I64d ",sum[x][y]==-1?-1:sum[x][y]-ln+1);
		}
		putchar(10);
	}
	return 0;
}