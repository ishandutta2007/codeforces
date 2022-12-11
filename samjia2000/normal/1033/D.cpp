#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int mo = 998244353;

map<LL,int>tim;

const int N = 505;

LL a[N];
int n;
bool d[N];

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

int main(){
	n=get();
	fo(i,1,n){
		LL v;
		cin>>v;
		//p^2
		LL p=sqrt(v);
		while(p*p>v)p--;
		while(p*p<v)p++;
		if (p*p==v){
			//p=q^2
			LL q=sqrt(p);
			while(q*q>p)q--;
			while(q*q<p)q++;
			if (q*q==p)tim[q]+=4;
			else tim[p]+=2;
			continue;
		}
		p=exp(log(v)/3);
		while(p*p*p>v)p--;
		while(p*p*p<v)p++;
		if (p*p*p==v){
			tim[p]+=3;
			continue;
		}
		//v=pq
		d[i]=1;
		a[i]=v;
	}
	bool cg=1;
	while(cg){
		cg=0;
		fo(i,1,n)
		if (d[i]){
			LL x=a[i];
			LL p=0,q=0;
			for(map<LL,int>::iterator h=tim.begin();h!=tim.end();h++){
				if (x%(*h).first==0){
					p=(*h).first;
					q=x/p;
					cg=1;
					break;
				}
			}
			if (p)tim[p]++,tim[q]++,d[i]=0;
		}
		fo(i,1,n)
		if (d[i]){
			fo(j,1,i-1)
			if (d[j]&&a[j]!=a[i]){
				LL g=gcd(a[j],a[i]);
				if (g>1){
					d[i]=d[j]=0;
					tim[g]+=2;
					a[j]/=g,a[i]/=g;
					tim[a[i]]++;
					tim[a[j]]++;
					cg=1;
					break;
				}
			}
		}
	}
	LL ans=1;
	for(map<LL,int>::iterator h=tim.begin();h!=tim.end();h++)ans=ans*((*h).second+1)%mo;
	fo(i,1,n)
	if (d[i]){
		int cnt=0;
		fo(j,1,n)
		if (d[j]&&a[j]==a[i]){
			if (j<i){cnt=0;break;}
			cnt++;
		}
		ans=ans*(cnt+1)%mo*(cnt+1)%mo;
	}
	cout<<ans<<endl;
	return 0;
}