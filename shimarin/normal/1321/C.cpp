//    
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 110;
int n,cnt;
char s[N],S[N];
bool flag[N];

int main(){
	n=read(),scanf("%s",s+1);
	int cao=n;
	Dow(i,25,1){
		while (2333){
			cnt=0;
			For(j,1,n) flag[j]=1;
			For(j,1,n) 
				if (s[j]=='a'+i)
					if ((j>1&&s[j-1]=='a'+i-1)||(j<n&&s[j+1]=='a'+i-1)) flag[j]=0;
			For(j,1,n) if (flag[j]) S[++cnt]=s[j];
			if (n==cnt) break;
			n=cnt;
			For(j,1,n) s[j]=S[j];
		//	For(j,1,n) printf("%c",s[j]);puts("");
		}
	}
	printf("%d\n",cao-n);
}