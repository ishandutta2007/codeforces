#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>

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

const int N = 3005;
const int L = 1e5+5;
const int INF = 1e9;

int n,m;
int a[N];
int val[N];
int ans[N][N];
int cnt[N];
bool sec[N];
int num[N],k;

bool cmp(int x,int y){return cnt[x]>cnt[y];}

int main(){
	n=get();m=get();
	fo(i,1,m)a[i]=get();
	fo(i,m+1,n)a[i]=a[m];
	fo(i,1,n)val[i]=a[i];
	int sum=0;
	fo(i,1,m)sum+=a[i];
	sum=n*(n-1)-sum;
	if (sum<0)return printf("no\n"),0;
	if (sum>0&&m==n)return printf("no\n"),0;
	if (m<n){
		int v=sum/(n-m),u=sum%(n-m);
		fo(i,m+1,m+u)val[i]=a[i]=v+1;
		fo(i,m+u+1,n)val[i]=a[i]=v;
		sum=0;
		if (m&&val[m+1]>val[m])return printf("no\n"),0;
	}
	fo(i,1,n)a[i]-=(i-1)*2;
	fo(i,1,n)fo(j,i+1,n)ans[j][i]=2;
	int pre=0;
	fo(i,1,n){
		fo(x,1,n)sec[x]=0,num[x]=x;
		sort(num+1,num+1+n,cmp);
		int h1=1,h2=1;
		int lef=0;
		k=0;
		if (a[i]>0){
			lef=min((i-1)*2,2*(n-i)-a[i]);
			cnt[i]=a[i];
		}
		else{
			lef=min((i-1)*2+a[i],2*(n-i));
			int tim=-a[i];
			while(tim){
				tim--;
				if (h2>n||cnt[num[h1]]>=cnt[num[h2]]){
					int x=num[h1];
					cnt[x]--;	
					ans[i][x]--,ans[x][i]++;
					h1++;
				}
				else{
					int x=num[h2];
					cnt[x]--;
					ans[i][x]--,ans[x][i]++;
					h2++;
				}
			}
		}
		while(lef&&(h1<=n||h2<=n)){
			lef--;
			if (h2>n||cnt[num[h1]]>=cnt[num[h2]]){
				int x=num[h1];
				cnt[x]--;
				ans[i][x]--,ans[x][i]++;
				cnt[i]++;
				h1++;
			}
			else{
				int x=num[h2];
				cnt[x]--;
				cnt[i]++;
				ans[i][x]--,ans[x][i]++;
				h2++;
			}
		}
	}
	fo(i,1,n)if (cnt[i])return printf("no\n"),0;
	fo(i,1,n){
		fo(j,1,n)val[i]-=ans[i][j];
		if (val[i]!=0)return printf("no\n"),0;
	}
	printf("yes\n");
	fo(i,1,n){
		fo(j,1,n)
		if (i==j)putchar('X');
		else putchar(ans[i][j]==0?'L':(ans[i][j]==1?'D':'W'));
		putchar('\n');
	}
	return 0;
}