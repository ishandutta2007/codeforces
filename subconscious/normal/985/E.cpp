#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=5e5+5;
int a[N],k,n,d;
int s[N],t[N];
int main(){
	scanf("%d%d%d",&n,&k,&d);
	rep(i,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	s[0]=1;t[1]=-1;
	int pos=1;
	rep(i,n){
		while(pos<n&&a[pos+1]-a[i]<=d)++pos;
		if(s[i-1]&&i+k-1<=pos)++t[i+k-1],--t[pos+1];
		s[i]=s[i-1]+t[i];
	}
	puts(s[n]>0?"YES":"NO");
    //system("pause");
    //2 2 4 7 7 7
}