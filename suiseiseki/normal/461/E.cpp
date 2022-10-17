#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
ll n,k;
struct Matrix{
	ll a[4][4];
	void clear(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix c;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				c.a[i][j]=n+1;
			}
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					c.a[i][k]=min(c.a[i][k],a.a[i][j]+b.a[j][k]);
				}
			}
		}
		return c;
	}
}a,b;
int V,tr[(Maxn*10<<1)|5][5],f[5][5][Maxn+5];
char s[Maxn+5];
void ins(int k){
	for(int i=k,j=1;(i<k+20)&&(s[i]);j=tr[j][s[i++]-'A']){
		if(!tr[j][s[i]-'A']){
			tr[j][s[i]-'A']=++V;
			f[s[k]-'A'][s[i]-'A'][i-k]++;
		}
	}
}
void ksm(Matrix a,ll n){
	while(n){
		if(n&1){
			b=(a*b);
		}
		a=(a*a);
		n>>=1;
	}
}
bool check(Matrix a){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a.a[i][j]<n){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	cin>>n;
	scanf("%s",s);
	V=1;
	for(int i=0;s[i];i++){
		ins(i);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=1;f[i][j][k]==(1<<((k<<1)-2));k++){
				a.a[i][j]=k;
			}
			a.a[i][j]++;
		}
	}
	k=n;
	for(ll i=0,j;i<k;){
		b.clear();
		j=((i+k+1)>>1);
		ksm(a,j);
		if(check(b)){
			i=j;
		}
		else{
			k=j-1;
		}
	}
	cout<<k+1<<endl;
	return 0;
}