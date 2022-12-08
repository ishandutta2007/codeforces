#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=200005;
int n,t,a;
char s[N];
bool isok=0;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&t);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='.'){isok=1;a=i;break;}
	if(!isok||!t) printf("%s\n",s+1);
	else{
	int len=n;s[0]='0';
	for(int i=a+1;i<=n;i++){
		if(s[i]>='5'){
			len=i-1;t--;
			if(i==a+1){
				s[a-1]++;
				s[a]=0;
				int k=a-1;
				while(s[k]=='9'+1) s[k]-=10,s[k-1]++,k--;
				len=a-1;
			}
			else{
				s[i-1]++;s[i]=0;
				int k=i-1;
				while(t&&s[k]>='5'){
					s[k-1]++,s[k]=0;
					if(s[k-1]=='.'+1){s[k-2]++,s[k-1]--;k-=2;t--;break;}
					k--;t--;
				}
				len=k;
//				printf("%d\n",k);
				while(s[k]=='9'+1||s[k]=='.'){
					if(s[k]>='9'+1) s[k]-=10,s[k-1-(s[k-1]=='.')]++;
					k--;
				}
			}
			break;
		}
	}
	isok=1;
	for(int i=1;i<=len;i++) if(s[i]=='.') isok=0;
	if(!isok){while(s[len]=='0'&&len) len--;}
	if(s[0]!='0') putchar(s[0]);
	for(int i=1;i<=len;i++) putchar(s[i]);
	puts("");
	}
	return 0;
}