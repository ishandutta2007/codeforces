#include <cstdio>
#include <algorithm>
const int Maxn=2000;
int n;
char s[Maxn+5][Maxn+5];
int l_pos[Maxn+5],r_pos[Maxn+5];
int ans[Maxn+5][2];
int ans_len;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+i);
		l_pos[i]=r_pos[i]=i;
	}
	ans_len=0;
	for(int len=2;len<=n;len++){
		for(int i=1,j;(j=i+len-1)<=n;i++){
			if(s[i][j]=='0'){
				continue;
			}
			if(l_pos[i]==l_pos[j]&&r_pos[i]==r_pos[j]){
				continue;
			}
			ans_len++,ans[ans_len][0]=i,ans[ans_len][1]=j;
			int lst_0=j,lst_1=i;
			for(int k=r_pos[i]+1;k<l_pos[j];k++){
				if(l_pos[k]==k){
					ans_len++,ans[ans_len][0]=lst_0,ans[ans_len][1]=k;
					lst_0=k,std::swap(lst_0,lst_1);
				}
			}
			int min_l=l_pos[i],max_r=r_pos[j];
			for(int k=min_l;k<=max_r;k++){
				l_pos[k]=min_l,r_pos[k]=max_r;
			}
		}
	}
	for(int i=1;i<=ans_len;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}