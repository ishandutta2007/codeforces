#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],m,n,t_case;
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    inline size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
int main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr();
		unordered_map<int,int,custom_hash>cnt;
		for(ri i=1;i<=n;++i)++cnt[qr()];
		ri cnt0=0;
		for(ri i=0;i<=n;++i)
			if(!cnt.count(i))
				++cnt0;
		priority_queue<int>q;
		ri sum=0;
		typedef pair<int,int> pii;
		#define fi first
		#define se second
		for(const pii &i:cnt)
			if(i.fi>n)
				q.push(i.se),sum+=i.se;
		ri ans=cnt.size();
		for(ri i=n;~i;--i){
			auto it=cnt.find(i);
			if(it==cnt.end())--cnt0;
			else q.push(it->se),sum+=it->se;
			while(sum>m)sum-=q.top(),q.pop();
			if(m>=cnt0)ckmin(ans,cnt0-i+(int)cnt.size()-(int)q.size());
		}
		qw(ans),putchar(10);
	}
	return 0;
}