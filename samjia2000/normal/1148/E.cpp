#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 3e5+5;

int n;
int s[N],t[N];
int m;
struct operation{
	int i,j,d;
	operation(const int i_=0,const int j_=0,const int d_=0){i=i_;j=j_;d=d_;}
}ans[N*5];
int num[N];

bool cmp(int x,int y){return s[x]<s[y];}

set<int>ss;
multiset<int>tt;

int main(){
	n=get();
	fo(i,1,n)s[i]=get();
	fo(i,1,n)t[i]=get();
	fo(i,1,n)num[i]=i;
	sort(t+1,t+1+n);
	sort(num+1,num+1+n,cmp);
	LL nows=0,nowt=0;
	fo(i,1,n){
		nows+=s[num[i]];
		nowt+=t[i];
		if (nows>nowt)return printf("NO\n"),0;
	}
	if(nows!=nowt)return printf("NO\n"),0;
	ss.clear();
	fo(i,1,n)
	if (s[num[i]]<t[i])ss.insert(i);
	fd(i,n,1)
	if (s[num[i]]>t[i]){
		for(;s[num[i]]>t[i];){
			set<int>::iterator h=ss.end();
			h--;
			int x=(*h);
			ss.erase(h);
			int tmp=min(s[num[i]]-t[i],t[x]-s[num[x]]);
			ans[++m]=operation(num[x],num[i],tmp);
			s[num[i]]-=tmp;
			s[num[x]]+=tmp;
			if (s[num[x]]<t[x])ss.insert(x);
		}
	}
	printf("YES\n");
	printf("%d\n",m);
	fo(i,1,m)printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].d);
	tt.clear();
	fo(i,1,n)tt.insert(s[i]);
	fo(i,1,n)
	if (tt.find(t[i])==tt.end())return fprintf(stderr,"Wrong\n"),0;
	else tt.erase(tt.find(t[i]));
	return 0;
}