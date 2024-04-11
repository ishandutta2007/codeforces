#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 202000
int pre[M][26],n;
char ch[M];
inline void solve(){
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++){
		memcpy(pre[i],pre[i-1],sizeof(pre[i-1]));
		pre[i][ch[i]-'a']++;
	}
	for(int Cas=read();Cas;--Cas){
		int l=read(),r=read(),mx=0,sc=0;
		if(l==r){puts("Yes");continue;}
		for(int i=0;i<26;i++){
			int num=pre[r][i]-pre[l-1][i];
			if(num>=mx) sc=mx,mx=num;
			else sc=max(sc,num);
		}
		if(sc==0){puts("No");continue;}
		if(r==l+1){puts("Yes");continue;}
		puts((mx+sc==r-l+1&&ch[r]==ch[l])?"No":"Yes");
	}
}
int main(){
	for(int Cas=1;Cas;--Cas) solve();
	return 0;
}