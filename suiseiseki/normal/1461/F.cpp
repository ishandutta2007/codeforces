#include <cstdio>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=100000;
int n,len;
int a[Maxn+5];
char s[5];
int id[Maxn+5];
ll b[Maxn+5];
ll f[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int lst[Maxn+5];
void calc(int left,int right){
	if(left>=right){
		return;
	}
	int len=0;
	for(int i=left,j;i<=right;i=j+1){
		j=i;
		ll mul=a[i];
		while(j<right&&((a[j+1]>1)==(a[i]>1))){
			j++;
			mul*=a[j];
		}
		len++;
		l[len]=i;
		r[len]=j;
		if(len&1){
			b[len]=mul;
		}
		else{
			b[len]=j-i+1;
		}
	}
	for(int i=1;i<=len;i++){
		ll mul=1;
		lst[i]=i;
		f[i]=f[i-1]+b[i];
		for(int j=i;j>0;j--){
			if(j&1){
				mul*=b[j];
			}
			if(f[j-1]+mul>f[i]){
				f[i]=f[j-1]+mul;
				lst[i]=j;
			}
		}
	}
	int i=len;
	while(i){
		int j=lst[i];
		if(i==j&&(!(i&1))){
			for(int k=l[j];k<r[j];k++){
				id[k]=0;
			}
		}
		else{
			for(int k=l[j];k<r[i];k++){
				id[k]=1;
			}
		}
		id[l[j]-1]=0;
		i=j-1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%s",s+1);
	while(s[++len]!='\0');
	len--;
	if(len==1){
		for(int i=1;i<=n;i++){
			printf("%d%c",a[i],(i==n?'\n':s[1]));
		}
		return 0;
	}
	if(len==2&&(s[1]=='-'||s[2]=='-')){
		int pos=(s[1]=='-'?2:1);
		if(s[pos]=='+'){
			for(int i=1;i<=n;i++){
				printf("%d%c",a[i],(i==n?'\n':s[pos]));
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(i<n&&a[i+1]==0){
					printf("%d-",a[i]);
					for(int j=i+1;j<=n;j++){
						printf("%d%c",a[j],(j==n?'\n':s[pos]));
					}
					break;
				}
				else{
					printf("%d%c",a[i],(i==n?'\n':s[pos]));
				}
			}
		}
		return 0;
	}
	for(int i=1;i<n;i++){
		if(a[i]>1&&a[i+1]>1){
			id[i]=1;
		}
		else if(a[i]==0||a[i+1]==0){
			id[i]=0;
		}
		else{
			id[i]=-1;
		}
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		ll mul=1;
		bool flag=0;
		while(j<n&&id[j]!=0){
			j++;
			if(!flag){
				mul*=a[j];
				if(mul>2*n){
					flag=1;
				}
			}
		}
		if(flag){
			int pos=i;
			while(pos<j&&a[pos]==1){
				id[pos]=0;
				pos++;
			}
			pos=j;
			while(pos>i&&a[pos]==1){
				id[pos-1]=0;
				pos--;
			}
			for(int k=i;k<j;k++){
				if(id[k]==-1){
					id[k]=1;
				}
			}
		}
		else{
			int pos_l=i,pos_r=j;
			while(pos_l<j&&a[pos_l]==1){
				id[pos_l]=0;
				pos_l++;
			}
			while(pos_r>i&&a[pos_r]==1){
				id[pos_r-1]=0;
				pos_r--;
			}
			calc(pos_l,pos_r);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",a[i],(i==n?'\n':(id[i]==0?'+':'*')));
	}
	return 0;
}