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

const int N = 5e5+5;

int n;
char s[N];
map<int,int>cnt0,cnt1;

int main(){
	n=get();
	int ans=0;
	int c0=0;
	fo(t,1,n){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int all=0,mi=0;
		fo(i,1,len){
			if (s[i]=='(')all++;else all--;
			mi=min(mi,all);
		}
		if (all==0){
			if (mi==0)c0++;
			continue;
		}
		if (all>0){
			int pre=all-mi;
			if (pre==all){
				if (cnt1[pre]){
					ans++;
					cnt1[pre]--;
				}
				else cnt0[pre]++;
			}
		}
		else{
			if (mi==all){
				int suf=-mi;
				if (cnt0[suf]){
					ans++;
					cnt0[suf]--;
				}
				else cnt1[suf]++;
			}
		}
	}
	ans=ans+c0/2;
	cout<<ans<<endl;
	return 0;
}