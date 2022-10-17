#include <cstdio>
#include <cstring>
#define ll long long
#define Maxn 200000
char s[Maxn+5],t[Maxn+5];
int n;
ll ans=0;
char d[Maxn+5];
int num_s[30],num_t[30];
void merge_sort(char *a,int left,int right){
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	merge_sort(a,left,mid);
	merge_sort(a,mid+1,right);
	int len=left-1;
	int i=left,j=mid+1;
	while(i<=mid&&j<=right){
		if(a[i]<=a[j]){
			d[++len]=a[i++];
		}
		else{
			d[++len]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid){
		d[++len]=a[i++];
	}
	while(j<=right){
		d[++len]=a[j++];
	}
	for(int i=left;i<=right;i++){
		a[i]=d[i];
	}
}
int main(){
	int q;
	scanf("%d",&q);
	ll ans_1,ans_2;
	bool flag;
	while(q--){
		memset(num_s,0,sizeof num_s);
		memset(num_t,0,sizeof num_t);
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=n;i++){
			num_s[s[i]-'a']++;
		}
		for(int i=1;i<=n;i++){
			num_t[t[i]-'a']++;
		}
		flag=0;
		for(int i=0;i<26;i++){
			if(num_s[i]!=num_t[i]){
				puts("NO");
				flag=1;
				break;
			}
		}
		if(flag){
			continue;
		}
		ans=0;
		merge_sort(s,1,n);
		ans_1=ans;
		ans=0;
		merge_sort(t,1,n);
		ans_2=ans;
		if((ans_1&1)==(ans_2&1)){
			puts("YES");
		}
		else{
			flag=0;
			for(int i=1;i<n;i++){
				if(s[i]==s[i+1]||t[i]==t[i+1]){
					flag=1;
					break;
				}
			}
			if(flag){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}