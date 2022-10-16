#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=5000;
const int Maxv=2000000;
const int Inf=0x3f3f3f3f;
int _num[Maxv<<1|5],*num=_num+Maxv;
void init(){
	memset(_num,0x3f,sizeof _num);
	num[0]=0;
	for(int i=1,val=1;i<6;i++,val=val*10+1){
		for(int j=-Maxv;j<=Maxv-val;j++){
			num[j+val]=std::min(num[j+val],num[j]+i);
		}
		for(int j=Maxv;j>=-Maxv+val;j--){
			num[j-val]=std::min(num[j-val],num[j]+i);
		}
	}
}
char s[Maxn+5];
int n;
int a[Maxn+5];
int _f[2][2][Maxn*20+5],*f[2][2];
void solve(){
	n=0;
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	std::reverse(a+1,a+1+n);
	a[n+1]=0;
	for(int i=1;i<=n;i++){
		a[i]*=9;
	}
	for(int i=1;i<=n;i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[n+1]){
		n++;
	}
	a[n+1]=0;
	int cur=0,nxt;
	int lst_min=0,lst_max=1;
	for(int i=lst_min;i<=lst_max;i++){
		f[cur][0][i]=f[cur][1][i]=Inf;
	}
	f[cur][0][0]=0,f[cur][1][1]=n;
	for(int i=n+1;i<=6;i++){
		a[i]=0;
	}
	for(int i=n;i>6;i--){
		nxt=cur^1;
		int cur_min=Inf,cur_max=-Inf;
		for(int j=lst_min;j<=lst_max;j++){
			if(f[cur][0][j]<Inf){
				cur_min=std::min(cur_min,j+a[i]),cur_max=std::max(cur_max,j+a[i]+1);
				f[nxt][0][j+a[i]]=std::min(f[nxt][0][j+a[i]],f[cur][0][j]+(i-1)*a[i]);
				f[nxt][1][j+a[i]+1]=std::min(f[nxt][1][j+a[i]+1],f[cur][0][j]+(i-1)*(a[i]+1));
				f[cur][0][j]=Inf;
			}
			if(f[cur][1][j]<Inf){
				cur_min=std::min(cur_min,j-10+a[i]),cur_max=std::max(cur_max,j-9+a[i]);
				f[nxt][0][j-10+a[i]]=std::min(f[nxt][0][j-10+a[i]],f[cur][1][j]+(i-1)*(10-a[i]));
				f[nxt][1][j-9+a[i]]=std::min(f[nxt][1][j-9+a[i]],f[cur][1][j]+(i-1)*(9-a[i]));
				f[cur][1][j]=Inf;
			}
		}
		cur=nxt;
		lst_min=cur_min,lst_max=cur_max;
	}
	int val=0;
	for(int i=6;i>0;i--){
		val=val*10+a[i];
	}
	int ans=Inf;
	for(int j=lst_min;j<=lst_max;j++){
		if(f[cur][0][j]<Inf){
			if((val+j)%9!=0){
				continue;
			}
			ans=std::min(ans,f[cur][0][j]+num[(val+j)/9]);
			f[cur][0][j]=Inf;
		}
		if(f[cur][1][j]<Inf){
			if((val-1000000+j)%9!=0){
				continue;
			}
			ans=std::min(ans,f[cur][1][j]+num[(val-1000000+j)/9]);
			f[cur][1][j]=Inf;
		}
	}
	printf("%d\n",ans);
}
int main(){
	init();
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			f[i][j]=_f[i][j]+Maxn*10+1;
		}
	}
	memset(_f,0x3f,sizeof _f);
	int T;
	T=1;
	while(T--){
		solve();
	}
	return 0;
}