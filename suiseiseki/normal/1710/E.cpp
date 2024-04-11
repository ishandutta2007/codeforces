// solution : https://www.cnblogs.com/Flying2018/p/acmicpc2874.html
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,m;
int a[Maxn+5],b[Maxn+5];
int pos_x[Maxn+5],pos_y[Maxn+5];
int s_x,s_y;
ll sum_x[Maxn+5];
ll get_sum_x(int l,int r){
	return sum_x[r]-sum_x[l-1];
}
ll find_val(int x,int y,bool flag){
	int ans=0;
	if(pos_x[x]<y){
		if(flag){
			if(s_x>x&&s_y>y){
				ans=1;
			}
			if(s_x<=x&&s_y<=x&&s_y<=pos_x[s_x]){
				ans=1;
			}
		}
		return 1ll*pos_y[y]*y+get_sum_x(pos_y[y]+1,x)+1ll*(n-x)*(m-y)-ans;
	}
	if(flag){
		if(s_x<=x&&s_y<=y){
			ans=1;
		}
		if(s_x>x&&s_y>y&&s_y>pos_x[s_x]){
			ans=1;
		}
	}
	return 1ll*x*y+1ll*(pos_y[y]-x)*m-get_sum_x(x+1,pos_y[y])+1ll*(n-pos_y[y])*(m-y)-ans;
}
bool check(int v){
	pos_x[0]=m;
	for(int i=1;i<=n;i++){
		pos_x[i]=pos_x[i-1];
		while(pos_x[i]>0&&a[i]+b[pos_x[i]]>v){
			pos_x[i]--;
		}
	}
	for(int i=1;i<=n;i++){
		sum_x[i]=sum_x[i-1]+pos_x[i];
	}
	pos_y[0]=n;
	for(int i=1;i<=m;i++){
		pos_y[i]=pos_y[i-1];
		while(pos_y[i]>0&&a[pos_y[i]]+b[i]>v){
			pos_y[i]--;
		}
	}
	ll mx_match=std::max(get_sum_x(1,n),1ll*n*m-get_sum_x(1,n)),d_match=std::max(get_sum_x(1,n)-(s_y<=pos_x[s_x]),1ll*n*m-get_sum_x(1,n)-(s_y>pos_x[s_x]));
	for(int i=1,j=1,k=1;i<=n;i++){
		while(j<m&&find_val(i,j,0)<=find_val(i,j+1,0)){
			j++;
		}
		while(k<m&&find_val(i,k,1)<=find_val(i,k+1,1)){
			k++;
		}
		mx_match=std::max(mx_match,find_val(i,j,0));
		d_match=std::max(d_match,find_val(i,k,1));
	}
	return mx_match!=d_match+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	s_x=a[1],s_y=b[1];
	std::sort(a+1,a+1+n),std::sort(b+1,b+1+m);
	s_x=std::lower_bound(a+1,a+1+n,s_x)-a,s_y=std::lower_bound(b+1,b+1+m,s_y)-b;
	int left=a[1]+b[1],right=a[s_x]+b[s_y];
	while(left<right){
		int mid=(left+right)/2;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
	return 0;
}