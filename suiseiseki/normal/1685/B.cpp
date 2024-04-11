#include <cstdio>
#include <algorithm>
const int Maxn=1000000;
int n;
char s[Maxn+5];
int a,b,c,d;
int num[2];
int lis_1[Maxn+5],len_1;
int lis_2[Maxn+5],len_2;
void solve(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	n=a+b+2*c+2*d;
	scanf("%s",s+1);
	num[0]=num[1]=0;
	for(int i=1;i<=n;i++){
		num[s[i]-'A']++;
	}
	if(num[0]!=a+c+d||num[1]!=b+c+d){
		puts("NO");
		return;
	}
	len_1=len_2=0;
	int sum_len=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(i==n||s[i]==s[i+1]){
			continue;
		}
		while(j<n&&s[j+1]!=s[j]){
			j++;
		}
		int len=j-i+1;
		if(len&1){
			sum_len+=len/2;
		}
		else{
			if(s[i]=='A'){
				lis_1[++len_1]=len/2-1;
			}
			else{
				lis_2[++len_2]=len/2-1;
			}
		}
	}
	std::sort(lis_1+1,lis_1+1+len_1),std::sort(lis_2+1,lis_2+1+len_2);
	int pos_1=1,pos_2=1;
	int sum_a=0,sum_b=0;
	while(pos_1<=len_1&&sum_a+lis_1[pos_1]<c){
		sum_a+=lis_1[pos_1]+1,pos_1++;
	}
	while(pos_1<=len_1){
		sum_len+=lis_1[pos_1++];
	}
	while(pos_2<=len_2&&sum_b+lis_2[pos_2]<d){
		sum_b+=lis_2[pos_2]+1,pos_2++;
	}
	while(pos_2<=len_2){
		sum_len+=lis_2[pos_2++];
	}
	int add_num=0;
	if(sum_a<c){
		add_num+=c-sum_a;
	}
	if(sum_b<d){
		add_num+=d-sum_b;
	}
	if(sum_len>=add_num){
		puts("YES");
	}
	else{
		puts("NO");
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