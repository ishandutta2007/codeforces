#include <ctime>
#include <cstdio>
#include <random>
using namespace std;
mt19937 rnd(time(NULL));
const int Maxn=1000000;
const int Maxb=1000000;
const int Maxm=100000;
const int Mod=1000000007;
const int Hash_len=2;
bool np[Maxb+5];
int p[Maxb+5],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxb;i++){
		if(!np[i]){
			p[++p_len]=i;
			if(1ll*i*i>Maxb){
				continue;
			}
			for(int j=i*i;j<=Maxb;j+=i){
				np[j]=1;
			}
		}
	}
}
int Base[Hash_len],h_Mod[Hash_len]={1000000007,1000000009};
void get_Base(){
	init();
	for(int i=0;i<Hash_len;i++){
		Base[i]=p[rnd()%p_len+1];
		while(Base[i]<=26){
			Base[i]=p[rnd()%p_len+1];
		}
	}
}
int n,q;
int len;
int m;
char s[Maxn<<1|5];
char t[Maxn+5];
char a[Maxn+5];
int a_len;
int a_val[Hash_len][Maxn+5];
int h_val[Hash_len][Maxn<<1|5];
int pow_B[Hash_len][Maxn+5];
int num[Maxm+5][26];
int pow_2[Maxm+5];
int m_len[Maxm+5];
void init_pow_2(){
	pow_2[0]=1;
	for(int i=1;i<=Maxm;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
int used_id;
void init_pow_B(){
	for(int i=0;i<Hash_len;i++){
		pow_B[i][0]=1;
		for(int j=1;j<=Maxn;j++){
			pow_B[i][j]=1ll*pow_B[i][j-1]*Base[i]%h_Mod[i];
		}
	}
}
void init_hash_s(){
	m=len;
	int id=1;
	while(m<=Maxn&&id<=n){
		for(int i=m+2;i<=(m<<1|1);i++){
			s[i]=s[i-(m+1)];
		}
		s[m+1]=t[id];
		m_len[id]=m;
		m=(m<<1|1);
		id++;
	}
	used_id=id-1;
	for(int i=0;i<Hash_len;i++){
		for(int j=1;j<=m;j++){
			h_val[i][j]=(1ll*h_val[i][j-1]*Base[i]+(s[j]-'a'+1))%h_Mod[i];
		}
	}
}
void init_hash_a(){
	for(int i=0;i<Hash_len;i++){
		for(int j=1;j<=a_len;j++){
			a_val[i][j]=(1ll*a_val[i][j-1]*Base[i]+(a[j]-'a'+1))%h_Mod[i];
		}
	}
}
int get_hash(int id,int *s,int l,int r){
	return (s[r]-1ll*s[l-1]*pow_B[id][r-l+1]%h_Mod[id]+h_Mod[id])%h_Mod[id];
}
bool equal(int l_a,int r_a,int l_b,int r_b){
	return get_hash(0,a_val[0],l_a,r_a)==get_hash(0,h_val[0],l_b,r_b)&&\
	get_hash(1,a_val[1],l_a,r_a)==get_hash(1,h_val[1],l_b,r_b);
}
int main(){
	init_pow_2();
	get_Base();
	init_pow_B();
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	while(s[++len]!='\0');
	len--;
	init_hash_s();
	for(int i=used_id+1;i<=n;i++){
		for(int j=0;j<26;j++){
			num[i][j]=(num[i-1][j]<<1)%Mod;
		}
		num[i][t[i]-'a']=(num[i][t[i]-'a']+1)%Mod;
	}
	for(int T=1;T<=q;T++){
		int k;
		scanf("%d",&k);
		scanf("%s",a+1);
		a_len=0;
		while(a[++a_len]!='\0');
		a_len--;
		init_hash_a();
		int ans=0;
		for(int i=1;i<=len-a_len+1;i++){
			if(equal(1,a_len,i,i+a_len-1)){
				ans=(ans+pow_2[k])%Mod;
			}
		}
		for(int i=1;i<=used_id&&i<=k;i++){
			for(int j=1;j<=a_len;j++){
				if(a[j]!=t[i]||j-1>m_len[i]||(a_len-j)>m_len[i]){
					continue;
				}
				if(equal(1,j-1,m-(j-1)+1,m)&&equal(j+1,a_len,1,a_len-j)){
					ans=(ans+pow_2[k-i])%Mod;
				}
			}
		}
		if(k>used_id){
			for(int i=0;i<26;i++){
				if(num[k][i]==0){
					continue;
				}
				for(int j=1;j<=a_len;j++){
					if(a[j]-'a'!=i||(j-1)>m||(a_len-j)>m){
						continue;
					}
					if(equal(1,j-1,m-(j-1)+1,m)&&equal(j+1,a_len,1,a_len-j)){
						ans=(ans+num[k][i])%Mod;
					}
				}
			}
		}
		printf("%d\n",(ans%Mod+Mod)%Mod);
	}
	return 0;
}