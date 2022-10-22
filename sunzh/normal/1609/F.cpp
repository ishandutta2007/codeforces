#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
typedef long long ll;
namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline ll read() {
    ll x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;
int n;
int a[1000010];
int cnt[1000010];
int stk1[1000010],top1;
int stk2[1000010],top2;
struct sgmt{
	int a[1000010],b[1000010];
	void upd(int x,int k){
		int p=x;
		while(x<=n){
			a[x]+=k;b[x]+=k*p;x+=x&-x;
		}
	}
	int qry(int x){
		int res1=0,res2=0,p=x;
		while(x){
			res1+=b[x];res2+=a[x];x-=x&-x;
		}
		return res2*(p+1)-res1;
	}
	void clear(){
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	}
	void update(int l,int r,int k){
		upd(l,k);upd(r+1,-k);
	}
	int query(int l,int r){
		return qry(r)-qry(l-1);
	}
}tr1,tr2;
signed main(){
	// freopen("F.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),cnt[i]=(a[i]?__builtin_popcountll(a[i]):0);//return 0;
	int ans=0;
	for(int o=0;o<=59;++o){
		int nws=0;
		top1=top2=0;tr1.clear(),tr2.clear();
		for(int i=1;i<=n;++i){
			while(top1&&a[stk1[top1]]>=a[i]){
				--top1;
				if(cnt[stk1[top1+1]]==o) nws-=tr2.query(stk1[top1]+1,stk1[top1+1]),tr1.update(stk1[top1]+1,stk1[top1+1],-1);
			}
			if(cnt[i]==o) nws+=tr2.query(stk1[top1]+1,i),tr1.update(stk1[top1]+1,i,1);
			stk1[++top1]=i;
			while(top2&&a[stk2[top2]]<=a[i]){
				--top2;
				if(cnt[stk2[top2+1]]==o) nws-=tr1.query(stk2[top2]+1,stk2[top2+1]),tr2.update(stk2[top2]+1,stk2[top2+1],-1);
			}
			if(cnt[i]==o) nws+=tr1.query(stk2[top2]+1,i),tr2.update(stk2[top2]+1,i,1);
			stk2[++top2]=i;
			// printf("o:%d,i:%d,nws:%lld\n",o,i,nws);
			ans+=nws;
		}
	}
	printf("%lld\n",ans);return 0;
}