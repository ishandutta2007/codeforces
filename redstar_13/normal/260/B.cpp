#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[100100];
int s[100100][10];
int f[20];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	f[1]=31;f[2]=28;f[3]=31;f[4]=30;f[5]=31;f[6]=30;f[7]=31;f[8]=31;f[9]=30;f[10]=31;f[11]=30;f[12]=31;
	cin>>a;
	int n=strlen(a);
	int r=0;
	for(int i=0;i<=n-10;i++) {
		if(a[i]>='0' and a[i]<='9' and a[i+1]>='0' and a[i+1]<='9' and a[i+2]=='-' and a[i+3]>='0' and a[i+3]<='9' and a[i+4]>='0' and a[i+4]<='9' and a[i+5]=='-' and a[i+6]>='0' and a[i+6]<='9' and a[i+7]>='0' and a[i+7]<='9' and a[i+8]>='0' and a[i+8]<='9' and a[i+9]>='0' and a[i+9]<='9'){
			int m=(a[i+3]-'0')*10+a[i+4]-'0';
			int d=(a[i]-'0')*10+a[i+1]-'0';
			int y=(a[i+6]-'0')*1000+(a[i+7]-'0')*100+(a[i+8]-'0')*10+a[i+9]-'0';
			if(d>f[m] or y>2015 or y<2013 or d==0 or m>12 or m==0) continue;
			r++;
			s[r][1]=d;
			s[r][2]=m;
			s[r][3]=y;
		}
	}
	int mx=0,T;
	for(int i=1;i<=r;i++){
		int t=0;
		for(int j=i;j<=r;j++) if(s[i][1]==s[j][1] and s[i][2]==s[j][2] and s[i][3]==s[j][3]) t++;
		if(t>mx) mx=t,T=i;
	}
	if(s[T][1]<10) cout<<'0';
	cout<<s[T][1]<<'-';
	if(s[T][2]<10) cout<<'0';
	cout<<s[T][2]<<'-';
	cout<<s[T][3]<<endl;
	return 0;
}