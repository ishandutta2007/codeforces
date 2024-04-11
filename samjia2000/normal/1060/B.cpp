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

const int INF = 1e9;

LL n;
int digi[100],len;
int f[100][2];

int main(){
	cin>>n;
	for(;n;n/=10)digi[++len]=n%10;
	int ans=0;
	fo(i,1,len)ans+=digi[i];
	f[len+1][0]=0;
	f[len+1][1]=-INF;
	fd(i,len,1){
		int v=digi[i];
		f[i][0]=f[i][1]=-INF;
		fo(c,0,1)
		if (f[i+1][c]>-INF){
			fo(x,0,9)
				fo(y,0,9)
				if (x+y<=c*10+v){
					int d=c*10+v-x-y;
					if (d==0||d==1){
						f[i][d]=max(f[i][d],f[i+1][c]+x+y);
					}
				}
		}
	}
	cout<<f[1][0]<<endl;
	return 0;
}