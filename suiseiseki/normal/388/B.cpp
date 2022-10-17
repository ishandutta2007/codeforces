#include <cstdio>
int a[35];
int mp[1005][1005];
int end[35][2];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int k;
	scanf("%d",&k);
	k--;
	int now=30;
	int len=0;
	while(k){
		if((1<<now)<=k){
			a[++len]=now;
			k-=(1<<now);
		}
		now--;
	}
	a[++len]=0;
	int tmp=3;
	int last;
	int lst[2];
	for(int i=1;i<=len;i++){
		if(a[i]==0){
			last=1;
			for(int j=1;j<=mx(a[1],1);j++){
				mp[last][tmp]=mp[tmp][last]=1;
				last=tmp;
				tmp++;
			}
			mp[2][last]=mp[last][2]=1;
			continue;
		}
		mp[1][tmp]=mp[tmp][1]=1;
		lst[0]=tmp;
		tmp++;
		mp[1][tmp]=mp[tmp][1]=1;
		lst[1]=tmp;
		tmp++;
		for(int j=2;j<=a[i];j++){
			mp[lst[0]][tmp]=mp[tmp][lst[0]]=1;
			mp[lst[1]][tmp]=mp[tmp][lst[1]]=1;
			tmp++;
			mp[lst[0]][tmp]=mp[tmp][lst[0]]=1;
			mp[lst[1]][tmp]=mp[tmp][lst[1]]=1;
			lst[0]=tmp-1;
			lst[1]=tmp;
			tmp++;
		}
		end[i][0]=lst[0];
		end[i][1]=lst[1];
	}
	for(int i=1;i<=len;i++){
		if(a[i]==0){
			continue;
		}
		if(a[1]-a[i]==0){
			mp[end[i][0]][2]=mp[2][end[i][0]]=1;
			mp[end[i][1]][2]=mp[2][end[i][1]]=1;
			continue;
		}
		mp[end[i][0]][tmp-(a[1]-a[i])]=mp[tmp-(a[1]-a[i])][end[i][0]]=1;
		mp[end[i][1]][tmp-(a[1]-a[i])]=mp[tmp-(a[1]-a[i])][end[i][1]]=1;
	}
	printf("%d\n",tmp-1);
	for(int i=1;i<tmp;i++){
		for(int j=1;j<tmp;j++){
			if(mp[i][j]){
				putchar('Y');
			}
			else{
				putchar('N');
			}
		}
		puts("");
	}
	return 0;
}