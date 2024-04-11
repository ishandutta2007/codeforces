#include <cstdio>
template<typename Elem>
void swap(Elem &a,Elem &b){
	Elem t=a;
	a=b;
	b=t;
}
const int Maxn=4000;
int n;
char s[Maxn+5];
int a[Maxn+5],b[Maxn+5];
int num_a[4],num_b[4];
int op[Maxn+5],op_len;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		for(int i=1;i<=n;i++){
			a[i]=s[i]-'0';
		}
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			b[i]=s[i]-'0';
		}
		for(int i=0;i<4;i++){
			num_a[i]=num_b[i]=0;
		}
		for(int i=1;i<=n;i+=2){
			num_a[a[i]<<1|a[i+1]]++;
			num_b[b[i]<<1|b[i+1]]++;
		}
		if(num_a[0]!=num_b[0]||num_a[3]!=num_b[3]){
			puts("-1");
			continue;
		}
		op_len=0;
		int rev=0;
		if(num_a[1]-num_a[2]!=num_b[1]-num_b[2]){
			int sum=num_a[1]-num_a[2];
			for(int i=1;i<=n;i+=2){
				if((a[i]<<1|a[i+1])==1){
					sum-=2;
				}
				else if((a[i]<<1|a[i+1])==2){
					sum+=2;
				}
				if(sum==num_b[1]-num_b[2]){
					rev=i;
					break;
				}
			}
			if(rev==0){
				sum=num_b[1]-num_b[2];
				for(int i=1;i<=n;i+=2){
					if((b[i]<<1|b[i+1])==1){
						sum-=2;
					}
					else if((b[i]<<1|b[i+1])==2){
						sum+=2;
					}
					if(sum==num_a[1]-num_a[2]){
						rev=-i;
						break;
					}
				}
			}
		}
		if(rev>0){
			op[++op_len]=rev+1;
			for(int i=1;i<=((rev+1)>>1);i++){
				swap(a[i],a[rev+1-i+1]);
			}
		}
		else if(rev<0){
			for(int i=1;i<=(((-rev)+1)>>1);i++){
				swap(b[i],b[(-rev)+1-i+1]);
			}
		}
		for(int i=1;i<=n-2;i+=2){
			int id;
			for(int j=i;j<=n;j+=2){
				if(a[j]==b[i]&&a[j+1]==b[i+1]){
					id=j;
					break;
				}
			}
			if(id-1>0){
				op[++op_len]=id-1;
				for(int j=1;j<=((id-1)>>1);j++){
					swap(a[j],a[id-j]);
				}
			}
			op[++op_len]=id+1;
			for(int j=1;j<=((id+1)>>1);j++){
				swap(a[j],a[id+1-j+1]);
			}
		}
		if(n-2>0){
			op[++op_len]=n-2;
			for(int i=1;i<=((n-2)>>1);i++){
				swap(a[i],a[(n-2)-i+1]);
			}
		}
		if(rev<0){
			op[++op_len]=(-rev)+1;
			for(int i=1;i<=(((-rev)+1)>>1);i++){
				swap(a[i],a[((-rev)+1)>>1]);
			}
		}
		printf("%d\n",op_len);
		for(int i=1;i<=op_len;i++){
			printf("%d ",op[i]);
		}
		puts("");
	}
	return 0;
}