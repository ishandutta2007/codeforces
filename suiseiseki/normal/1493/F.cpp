#include <cstdio>
#include <algorithm>
const int Maxn=1000;
int n,m;
bool flag_nm;
bool ask(int h,int w,int x_1,int y_1,int x_2,int y_2){
	if(flag_nm){
		printf("? %d %d %d %d %d %d\n",w,h,y_1,x_1,y_2,x_2);
	}
	else{
		printf("? %d %d %d %d %d %d\n",h,w,x_1,y_1,x_2,y_2);
	}
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int p[55];
int len;
void find_p(int n){
	len=0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			len++;
			p[len]=i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		len++;
		p[len]=n;
	}
}
int lis[Maxn+5],lis_len;
bool check_dfs(int x,int len){
	if(x==1){
		return 1;
	}
	int mid=(x>>1);
	if(ask(mid*len,m,lis[1],1,lis[x-mid+1],1)){
		if(check_dfs(x-mid,len)){
			return 1;
		}
		return 0;
	}
	return 0;
}
bool check(int x,int tmp){
	lis_len=0;
	for(int i=1;i<=tmp;i+=x){
		lis[++lis_len]=i;
	}
	if(check_dfs(lis_len,x)){
		return 1;
	}
	return 0;
}
int work(){
	int ans=1;
	find_p(n);
	for(int i=1;i<=len;i++){
		int tmp_n=n,num=0;
		while(tmp_n%p[i]==0){
			if(check(tmp_n/p[i],tmp_n)){
				num++;
				tmp_n/=p[i];
			}
			else{
				break;
			}
		}
		ans*=(num+1);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	int ans=work();
	flag_nm=1;
	std::swap(n,m);
	ans*=work();
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}