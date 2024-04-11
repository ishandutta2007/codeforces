#include <cstdio>
#define Maxn 100000
char s[Maxn+5];
struct Seg{
	int left,right;
	bool g_s;
}seg[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int len=0;
	int now=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i+1;
		while(j<=n&&s[j]==s[i]){
			j++;
		}
		j--;
		seg[++len].left=i;
		seg[len].right=j;
		if(s[i]=='G'){
			seg[len].g_s=0;
			now++;
		}
		else{
			seg[len].g_s=1;
		}
	}
	if(len==1){
		if(seg[1].g_s==0){
			printf("%d\n",n);
		}
		else{
			puts("0");
		}
	}
	else{
		int ans=0;
		for(int i=1;i<=len;i++){
			if(seg[i].g_s==1){
				continue;
			}
			if(i>len-2){
				if(now>1){
					ans=mx(ans,seg[i].right-seg[i].left+2);
				}
				else{
					ans=mx(ans,seg[i].right-seg[i].left+1);
				}
			}
			else{
				if(seg[i+1].left==seg[i+1].right){
					if(now>2){
						ans=mx(ans,seg[i].right-seg[i].left+1+seg[i+2].right-seg[i+2].left+1+1);
					}
					else{
						ans=mx(ans,seg[i].right-seg[i].left+1+seg[i+2].right-seg[i+2].left+1);
					}
				}
				else{
					if(now>1){
						ans=mx(ans,seg[i].right-seg[i].left+2);
					}
					else{
						ans=mx(ans,seg[i].right-seg[i].left+1);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}