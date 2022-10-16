#include <cstdio>
#include <algorithm>
const int Maxn=5000000;
int n;
char s[Maxn+5];
int k;
namespace Subtask_1{
	char a[Maxn+5];
	void work(){
		for(int i=1;i<=n;i++){
			a[i]=s[i];
		}
		std::reverse(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]!=s[i]){
				if(a[i]>s[i]){
					std::swap(a,s);
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			putchar(a[i]);
		}
		puts("");
	}
	bool check(){
		return k==1;
	}
}
int pos[Maxn+5],len[Maxn+5],p_len;
void Lydon(char *s,int n,int *pos,int *len,int &p_len){
	p_len=0;
	for(int i=1,j,k;i<=n;){
		j=i,k=i+1;
		while(k<=n&&s[j]<=s[k]){
			if(s[j]==s[k]){
				j++;
			}
			else{
				j=i;
			}
			k++;
		}
		while(i<=j){
			i+=k-j;
		}
		pos[++p_len]=i-1;
		len[p_len]=k-j;
	}
}
void calc_greater_2(){
	for(int i=pos[p_len-1]+1;i<=pos[p_len];i++){
		putchar(s[i]);
	}
	k-=((len[p_len]!=1)||(len[p_len-1]!=1));
	p_len--;
}
char ans[Maxn+5];
void check_ans(char *s){
	for(int i=1;i<=n;i++){
		if(s[i]!=ans[i]){
			if(s[i]<ans[i]){
				for(int j=1;j<=n;j++){
					ans[j]=s[j];
				}
			}
			break;
		}
	}
}
void update_1(){
	std::reverse(s+1,s+1+n);
	check_ans(s);
	std::reverse(s+1,s+1+n);
}
void update_2(){
	static char t[Maxn<<1|5];
	for(int i=1;i<=n;i++){
		t[i]=t[i+n]=s[i];
	}
	int pos=1;
	for(int i=1,j,k;i<=n;){
		pos=i;
		j=i,k=i+1;
		while(k<=(n<<1)&&t[j]<=t[k]){
			if(t[j]==t[k]){
				j++;
			}
			else{
				j=i;
			}
			k++;
		}
		while(i<=j){
			i+=k-j;
		}
	}
	check_ans(t+pos-1);
}
void z_fun(char *s,int n,int *z){
	for(int i=1;i<=n;i++){
		z[i]=0;
	}
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i<=r){
			z[i]=std::min(z[i-l+1],r-i+1);
		}
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1]){
			z[i]++;
		}
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
}
void ex_kmp(char *s,char *t,int n,int *z,int *p){
	z_fun(t,n,z);
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
	for(int i=1,l=0,r=0;i<=n;i++){
		if(i<=r){
			p[i]=std::min(z[i-l+1],r-i+1);
		}
		while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1]){
			p[i]++;
		}
		if(i+p[i]-1>r){
			l=i;
			r=i+p[i]-1;
		}
	}
}
void update_3(){
	static char t[Maxn+5];
	static int z[Maxn+5],p[Maxn+5];
	for(int i=1;i<=n;i++){
		t[i]=s[i];
	}
	std::reverse(t+1,t+1+n);
	ex_kmp(t,s,n,z,p);
	std::reverse(p+1,p+1+n);
	int pos=n;
	for(int i=n-1;i>0;i--){
		if(p[pos-1]<pos-i){
			if(s[pos-1-p[pos-1]]<s[p[pos-1]+1]){
				pos=i;
			}
		}
		else if(z[pos-i+1]<i-1){
			if(s[z[pos-i+1]+1]<s[pos-i+1+z[pos-i+1]]){
				pos=i;
			}
		}
	}
	std::reverse(s+1,s+pos);
	std::reverse(s+1,s+1+n);
	check_ans(s);
	std::reverse(s+1,s+1+n);
	std::reverse(s+1,s+pos);
}
void update_4(){
	int p=p_len;
	while(p>1){
		bool flag=1;
		for(int i=pos[p-1]+1,j=pos[p-2]+1;flag&&i<=pos[p];i++,j++){
			if(s[i]!=s[j]){
				flag=0;
			}
		}
		if(!flag){
			break;
		}
		p--;
	}
	int q=p;
	while((++q)<=p_len){
		for(int i=pos[q-1],j=pos[q-2]+1+n-i;i>pos[q-2];i--,j++){
			if(s[i]==s[j]){
				continue;
			}
			if(s[i]<s[j]){
				p=q;
			}
			break;
		}
	}
	std::reverse(s+pos[p-1]+1,s+1+n);
	std::reverse(s+1,s+1+n);
	check_ans(s);
	std::reverse(s+1,s+1+n);
	std::reverse(s+pos[p-1]+1,s+1+n);
}
void calc_equal_2(){
	for(int i=1;i<=n;i++){
		ans[i]=s[i];
	}
	update_1(),update_2(),update_3(),update_4();
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	scanf("%d",&k);
	if(Subtask_1::check()){
		Subtask_1::work();
		return 0;
	}
	std::reverse(s+1,s+1+n);
	Lydon(s,n,pos,len,p_len);
	while(k>=3&&p_len){
		calc_greater_2();
	}
	if(p_len>0){
		n=pos[p_len];
		calc_equal_2();
		for(int i=1;i<=n;i++){
			putchar(ans[i]);
		}
	}
	puts("");
	return 0;
}